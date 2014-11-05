################################################################################
#                                                                              #
#                         Pfix by Florian Schneider                            #
#                                                                              #
#     Pfix is just a simple C++ program to convert Infix math terms to their   #     
#     Postfix form with some small helpful flagoptions.                        #
#                                                                              #
#     To convert a given term you just start the program from the shell.       #
#     Depending on the flags you can load the input from a file or write it    #
#     down when you are ask for. Pfix already loads the 4 standard operators   #
#     +, -, * and / , but you can add additional operators by using the        #
#     operator-file flag. This then loads additional given operators from a    #
#     file where you put them. Each operator also needs a certain priority     #
#     E.g: while + and - have priority 1, * and / have 2.                      #
#                                                                              #
#     There is also a flag to display used operators and their priorities or   #
#     to save the result and the optional operator list to a txt file          #  
#                                                                              #
#                           Things which are needed                            #
#                                                                              #
#     -> Exception Handling                                                    #
#     -> The fancy convertion algorithm                                        #
#     -> Reading and adding new operators from file                            #
#     -> Displaying new operators when needed (standard ones already are)      #
#                                                                              #
#                         Things which are already in                          #
#                                                                              #
#     -> Flag Handling                                                         #
#     -> Reading input from file                                               #
#     -> Saving output to file                                                 #
#     -> Displaying / Saving of standard operators                             #
#     -> operators                                                             #
#        -> saved in map as sign(string) to priority(unsigned int)             #
#     -> A makefile with make / make clean / make run                          #
#        -> Regarding make run: to use flags you have to put them into the     #
#           EXEFLAG of the makefile or run the programm with ./pfix -flags     #
#                                                                              #
################################################################################
asdfasdfasd