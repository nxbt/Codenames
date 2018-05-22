# How to play
Here's a link to the rules for how to play codenames: https://czechgames.com/files/rules/codenames-rules-en.pdf

Only the spymasters should look at the output of the program, and then write out the names on the grid on a piece of paper 
(no colors!). Red and blue are the agents for the two teams, white are the bystander, and green in the assasin.

# Setup
In order to play, you'll need a list of words. Make a file called 'codenames.data' and put each word on a seperate line. The program will automatically read this file to pick words for the grid. Words won't be picked twice, so you'll need at least 25 words. In your codenames.data.

# Known Bugs
* Sometimes, a blank line will show up. This may not happen with your word list, we're still trying to figure out what causes this.
