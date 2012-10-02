Compile with make

My shell works with the readline function, and uses strtok to split the arguments. 
It seems to be fully functional as far as calling commands.

Room for improvement:

using readline should allow me to use ctrl-r to reverse search through commands, but 
this funcitonality doesn't work.

I also cannot use the up arrow to go to previous commands.

Questions:

Currently, I have an exception for the cd command.  While I am ok with this exception,
how do I know there are not other functions that require another exception?
