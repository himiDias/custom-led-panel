import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'


function App() {
  const [count, setCount] = useState(0)

  return (
    <>
      <div id = "container">
        <div id = "dpad">
          <ControllerButton id = "dpad-u" text = "Up" />
          <ControllerButton id = "dpad-d" text = "Down" />
          <ControllerButton id = "dpad-l" text = "Left" />
          <ControllerButton id = "dpad-r" text = "Right" />
        </div>
        
        <div id = "header">
          <h1 class = "screen-title">LED Controller</h1>
          <button id = "btn-fs" onClick={enterLandscape}>Fullscreen</button>
        </div>
        
        <div id = "buttons">
          <ControllerButton id = "btn-a" text = "A" />
          <ControllerButton id = "btn-b" text = "B" />
          <ControllerButton id = "btn-x" text = "X" />
          <ControllerButton id = "btn-y" text = "Y" />
        </div>
      </div>
    </>
  )
}

function ControllerButton({id,text}){
  return (
    <button id = {id} onClick={() => handleClick(id)}>{text}</button>
  )
  
  function handleClick(id){
    console.log("Button : ",id," clicked");
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

export default App
