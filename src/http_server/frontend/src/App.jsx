import { useEffect, useRef, useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'


function App() {
  const [count, setCount] = useState(0);
  // change back to 'main', using diffreent for developing
  const [currentPage, setCurrentPage] = useState('paint');
  
  const socketRef = useRef(null);
  
  
  useEffect(() => {
    const hostname = window.location.hostname;
    const socket = new WebSocket(`ws://${hostname}:18080/ws`);
    socketRef.current = socket;
    
    socket.onopen = () => {
      console.log("Websocket : connection opened");
    };
    
    socket.onmessage = (event) => {
      const msg = event.data;
      console.log("Websocket : received from server : ",msg);
      //concern regarding using hardcoded index values, consider different approach using a struct perhaps
      let sep = msg.search(":");
      if (msg.substring(1,sep) == "'switch_screen'"){
        setCurrentPage(msg.substring(sep+2,msg.length-2));
      }
    };
    
    socket.onclose = () =>{
      console.log("Websocket : connection closed closed");
    };
    
    return () => {
      socket.close();
    };
    
    
  },[]);
  
  const renderPage = () => {
    switch (currentPage){
      case 'main':
        return <MainPage  socketRef = {socketRef}/>;
      case 'settings':
        return <SettingsPage socketRef = {socketRef}/>;
      case 'paint':
        return <PaintPage socketRef = {socketRef}/>;
      default:
        return <ErrorPage/>;
    }
  };
  
  return (
    <>
      <div id = "main">
        {renderPage()}
      </div>
    </>
  )
}

const MainPage = ({socketRef}) => {
  return (
    <div id = "container">
        <div id = "dpad">
          <ControllerButton id = "dpad-u" text = "Up" socket = {socketRef}/>
          <ControllerButton id = "dpad-d" text = "Down" socket = {socketRef}/>
          <ControllerButton id = "dpad-l" text = "Left" socket = {socketRef}/>
          <ControllerButton id = "dpad-r" text = "Right" socket = {socketRef}/>
        </div>
        
        <div id = "header">
          <h1 className = "screen-title">LED Controller</h1>
          <button id = "btn-fs" onClick={enterLandscape}>Fullscreen</button>
        </div>
        
        <div id = "buttons">
          <ControllerButton id = "btn-a" text = "A" socket = {socketRef}/>
          <ControllerButton id = "btn-b" text = "B" socket = {socketRef}/>
          <ControllerButton id = "btn-x" text = "X" socket = {socketRef}/>
          <ControllerButton id = "btn-y" text = "Y" socket = {socketRef}/>
        </div>
      </div>
  )

}

function ControllerButton({id,text,socket}){
  return (
    <button id = {id} onClick={() => handleClick(id)}>{text}</button>
  )
  
  function handleClick(id){
    console.log("Button : ",id," clicked");
    const message = JSON.stringify({type: 'action',id});
    //const idObj = JSON.parse(msg);
    
    //const message = JSON.stringify({
    socket.current.send(message);
  }
}

async function enterLandscape(){
  try{
    await document.documentElement.requestFullscreen();
    
    if (screen.orientation && screen.orientation.lock){
      await screen.orientation.lock("landscape");
    }
    
    console.log("Orientation locked to landscape");
    }catch(err){
      console.error("Orientation failed: ",err);
    }
}


const SettingsPage = ({socketRef}) =>{

  const [formData, setFormData] = useState({
    type : 'submit-settings',
    status: 'Set Status Message',
    time : false,
    date : false,
  });
  
  const handleChangeText = (e) => {
    setFormData({
      ...formData,
      [e.target.name]:e.target.value
    });
  };
  
  const handleChangeBool = (e) => {
    setFormData({
    ...formData,
      [e.target.name]:e.target.checked
    });
  };

  const handleSubmit = (e) => {
    e.preventDefault();
    
    
    const message = JSON.stringify(formData);
    console.log(message);
    socketRef.current.send(message);
  };
  
  const handleCancel = (e) => {
    const message = JSON.stringify({type:'cancel-settings'});
    console.log(message);
    socketRef.current.send(message);
  
  };



  return (
    <div>
      <div id = "form-container">
        <h1 className="screen-title"> Settings </h1>
        <form id = "settings-form" onSubmit={handleSubmit}>
          <div className = "form-question">
            <label htmlFor="status">Status Message:</label>
            <input type="text" id="status" name="status" value={formData.status} onChange={handleChangeText}></input> 
          </div>
          
          <div className = "form-question">
            <input type="checkbox" id="time" name="time" value="Time" onChange={handleChangeBool}></input>
            <label htmlFor="time">Display Time</label> 
          </div>
          
          <div className = "form-question">
          <input type="checkbox" id="date" name="date" value="Date" onChange={handleChangeBool}></input>
          <label htmlFor="date">Display Date</label> 
          </div>
          
          <div className = "form-question action">
            <input type="button" id="cancel" name="cancel" value="Cancel" onClick={handleCancel}></input>
            <input type="submit" id="submit" value="Submit"></input>
          </div>
          
        </form>
      </div>
    </div>
  )
}

const PaintPage = ({socketRef}) => {
  
  const PixelButton = ({x_coord,y_coord,colour}) =>{
    return <button className = "paint-button" data-x = {x_coord} data-y = {y_coord} data-col = {colour} onClick={handleSetPixel}></button>
  }
  
  const handleSetPixel = (e) =>{
    
  
  
  
  
    const x = e.target.getAttribute("data-x");
    const y = e.target.getAttribute("data-y");
    const colour = e.target.getAttribute("data-col");
    
    let message = "";
    if (colour == "null"){
      message = JSON.stringify({type: 'setpixel-paint',x,y,colour});
    }
    else{
      message = JSON.stringify({type: 'clearpixel-paint',x,y});
    }
   
    // Change when colour is null to be clearpixel-paint
    console.log(message);
    
    //socketRef.current.send(message);
    
  }

  const gridSize = 62;
  
  

  return(
    <div id = "paint-container">
      <h1 className = "screen-title">Paint</h1>
      <div id = "paint-options">
        <div id = "colour-selector">
        colour selector
        </div>
        <div id = "paint-grid">
            {Array.from({ length:gridSize}, (_, x) => 
              Array.from({ length:gridSize}, (_, y) => (
              <PixelButton x_coord = {x} y_coord = {y} colour = {null}/>
              ))
            )}
        </div>
        <div id = "tool-selector">
        tool selector
        </div>
      </div>
      <div id = "save-options">
        <button>Back</button>
      </div>
    </div>
  )


}

const ErrorPage = () =>{
  return (
    <div>
      <h1> ERROR PAGE </h1>
    </div>
  
  )

}


export default App
