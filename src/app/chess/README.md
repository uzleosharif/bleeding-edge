

this is effort towards building a chess game 

# GUI
- using `Qt`
- setup the main window for game by adding a central widget and laying out necessary child widgets. You can use 
  c++ api to set up the layout programmatically
- create chess board using `QGridLayout` and `QLabel` widgets to represent each square on the board. You can use 
  `QPixmap` objects to display the chess pieces on the board
- implement the game logic (engine) using a separate class. This should handle the rules of the game, including 
  checking for legal moves, detecting checkmate and stalemate, and determining when the game is over
- connect the GUI to the engine by setting up signals and slots in `Qt`. For example, you can create a signal that 
  is emitted when the user clicks on a chess piece, and connect this signal to a slot that handles the move.
- test game

# notes
## design
- layer based design
- user/player | gui layer | engine layer

### gui layer
- shows state of the game
- user uses this to modify the state of the game

### engine layer
- keep track of the game state
- game logic: making and validating moves, detecting checkmate and stalemate, and determining when game is over

## chess engine isolated from gui 
it is possible to implement a chess engine that is independent of the GUI framework you are using. This can be useful 
if you want to be able to easily switch to a different GUI framework or reuse the chess engine in other projects.

One way to achieve this is to create a separate class for the chess engine that has no dependencies on any specific 
GUI framework. This class should handle all the game logic, including making and validating moves, detecting 
checkmate and stalemate, and determining when the game is over.

You can then create a separate GUI layer that uses this chess engine class to display the game state and handle 
user input. The GUI layer can be implemented using any framework you choose such as Qt and will act as a bridge 
between the chess engine and user.

To switch to a different GUI framework, you would simply need to reimplement the GUI layer using the new 
framework, while leaving the chess engine unchanged. This can help make your code more modular and easier to 
maintain. 