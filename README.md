# MyPong

**PONG recreated in C++ by me.**

This short project was made using the "raylib" library. It was made as practice for my videogame programming skills.

For downloading and testing the game follow these steps:

1. In the repo page click on the green "<> Code" button and click on "Download ZIP".
2. Once downloaded, you can leave the ZIP in the downloads folder or move it to the folder of your preference.
3. Right-click on the ZIP and click on the "Extract" option.
4. Once extracted, a folder with the same name as the ZIP + "- main" will be added in the same folder where you previosuly saved the ZIP.
5. Double-click in the folder; you should see the same files that are in the repo.
6. To play, double-click in the file called "pong" with the extension .exe; if you don't see the extension locate the file tipe "application" or "executable".


# Now you can play!

**Here are the rules**:

-Player 1 (Left-Paddle): "W" key to move up. "S" key to move down.

-Player 2 (Right-Paddle): "Up Arrow" key to move up. "Down Arrow" key to move down.

-To shoot the ball use the "Spacebar" key.

-In case the ball is moving way to slow you can restart the game by using the "P" or the "R" key. If you use the "P" key it will add a point to the Left-Padddle player, and if you use the "R" key it will add a point to the Right-Padddle player.

-Every 10 points (no matter the player), the difficulty will increase a little bit; you will notice this given that the paddle speed and the ball speed will increase.

-------------------------------------------------------------------------------------------------------

-**NOTE**:

- You can change the Player names shown in the screen if you edit the pong.cpp file. It is recommended that you use an IDE. Here is how:
 
1. Go to line 141 and 142.
2. Once there you will see 2 functions called "DrawText()" and inside that method there is another one called "TextFormat()".
3. Inside "TextFormat()", at the beginning there is a string; by default in line 141 it says "PLAYER 1: %d", and in line 142 it says "PLAYER 2: %d".
4. You can ONLY modify everything before the semicolon " : ", otherwise the game won't work correctly. In there add your name, and in the next line the other name.
