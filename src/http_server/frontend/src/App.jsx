import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'


function App() {
  const [count, setCount] = useState(0)

  return (
    <>
      <h1>LED Controller</h1>
      
      <div id = "dpad">
        <ControllerButton id = "dpad-u" text = "Up" />
        <ControllerButton id = "dpad-d" text = "Down" />
        <ControllerButton id = "dpad-l" text = "Left" />
        <ControllerButton id = "dpad-r" text = "Right" />
      </div>
      
      <div id = "buttons">
        <ControllerButton id = "btn-a" text = "A" />
        <ControllerButton id = "btn-b" text = "B" />
        <ControllerButton id = "btn-x" text = "X" />
        <ControllerButton id = "btn-y" text = "Y" />
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

export default App
