//temporary server to test websocket

import {WebSocketServer} from 'ws';

const wss = new WebSocketServer({port:8080});

wss.broadcast = function broadcast(data) {
	wss.clients.forEach(function each(client) {
		if (client.readyState == WebSocketServer.OPEN){
			client.send(data);
		}
	});
	
};


wss.on('connection',(ws) => {
	console.log('Client connected');
	
	ws.send('Connected to websocket server');
	
	ws.on('message', (message) => {
		console.log(`Received: ${message}`);
		
		wss.broadcast(message);
	});
	
	ws.on('close', () => {
		
		console.log('Client disconnected');
	});
	
});

console.log('WebSocket server running on ws://localhost:8080');
