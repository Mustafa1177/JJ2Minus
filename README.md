# MinusTemp
JJ2Minus is a patch for the game jazz Jackrabbit 2


# Getting Started
Tutorial on adding a JJ2 variable for reading/writing.

1- Find the address you want to add, you can find some game addresses in the link below:

https://www.jazz2online.com/wiki/List_of_Jazz_Jackrabbit_2_Memory_Addresses

2- Open the "addresses_table.h" file and define the address inside the "GameAddressTable" structure.

![image](https://github.com/Mustafa1177/MinusTemp/assets/88726201/e2598f9f-e3a6-452d-9a14-f84fbc82fa82)

3- Now go to "addresses_table.cpp" and assign a value for the variable you defined in the previous step inside the "GameAddressTableTSF" or "GameAddressTableV23" structure depending on the game version you are targeting.

![image](https://github.com/Mustafa1177/MinusTemp/assets/88726201/ea58eae9-e2e1-4f66-a033-90a8314afe1d)

4- Go add an external pointer to the game variable inside the file "jjvariables.h" with the right type so that we can access it from other files.

![image](https://github.com/Mustafa1177/MinusTemp/assets/88726201/73279272-8cb0-4945-b4aa-60e8f5c75e54)

5- Now, we need to assign the address we added previously as the value for the pointer we defined last step. We will accomplish that using the "init" function inside the file "jjvariables.cpp". The "init" function is called at the start of the program which lets us assign the addresses to the pointers.

![image](https://github.com/Mustafa1177/MinusTemp/assets/88726201/b30a23e6-1ad0-4f2b-bd97-f7eea987eb95)

6- Now we have everything set up! You can now read/write the value of the variable by using the poiter we added:
*JJVariables::GameMode = 2;*
Don't forget to include the "jjvariables.h" header file.


