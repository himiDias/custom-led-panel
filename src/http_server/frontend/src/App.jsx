import { useEffect, useRef, useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'


function App() {
  const [count, setCount] = useState(0);
  const [currentPage, setCurrentPage] = useState('main');
  
  const socketRef = useRef(null);
  
  
  useEffect(() => {
    const hostname = window.location.hostname;
    const socket = new WebSocket(`ws://${hostname}:18080/ws`);
    socketRef.current = socket;
    
    socket.onopen = () => {
      console.log("Websocket : connection opened");
    };
    
    socket.onmessage = (event) => {
      console.log("Websocket : received from server : ",event.data);
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
        return <SettingsPage />;
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
    const message = JSON.stringify({id});
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


const SettingsPage = () =>{
  return (
    <div>
      <h1> Settings </h1>
    </div>
  )
}


export default App
