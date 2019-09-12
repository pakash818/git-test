package client;

import java.io.IOException;
import java.net.Socket;
import java.util.concurrent.ExecutorService;

import ui.IView;
import ui.View;

public class Controller implements IController {
	private IView view;
	private Client client;
	private ExecutorService executor;
	private Socket socket;

	public Controller(ExecutorService executor) {
		this.executor = executor;
		this.view = new View(this);
		view.display();
	}


	public void testFUNC() {

	}

}
