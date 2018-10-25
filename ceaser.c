/*John Pwajok
    Encryption and Decryption using the ceaser cipher 
    Shift is decided by user and not hardcoded to 3
*/
#include<stdio.h>
 
int main()
{
    char message[1000];
    char current;
    int i;
    int key;
    int choice;
    
    //Enter the message that is to be converted
    printf("Please enter your message \n");
    //Take the users message
    gets(message);
    //Select what key you want to use to encrypt or decrypt the message
    printf("Please enter the key you would like to use\n ");
    //Take the users key
    scanf("%d", &key);
    //Give the user the choice to encrypt or decrypt the message ([1] or [2])
    printf("Would you like to encrypt [1] or decrypt [2] this message?\n");
    //Take in the users choice
    scanf("%d", &choice);

////////////////////////////////////////////////////////////////////////////////////
    //If the users choice is to encrypt the message
    if (choice == 1)
    {
        //Start at position 0 of the string unless it's empty and increment from there
        for(i = 0; message[i] != '\0'; ++i)
        {
            //current letter is current position of 'i'
           current = message[i];
            //if current character is between 'a' and 'z'
            if(current >= 'a' && current <= 'z')
            {
                //current character is changed to character key* places up from current character
                current = current + key;
            //in order to go past 'z' and back to start at 'a' without going into special characters
                if(current > 'z')
                {
                    //simply move back 26 spaces and continue
                    current = current - 26;
                }
            
                //set character value to new value  from current position 
                message[i] = current;
            }

            //FOR CAPITAL CHARACTERS
            else if(current >= 'A' && current <= 'Z')
            {
                current = current + key;
            
                if(current > 'Z')
                {
                    current = current - 26;
                }
            
                message[i] = current;
            }
        }
        //print encrypted message
        printf ("Your new message is: %s", message);
    
        return (0);

    }

/////////////////////////////////////////////////////////////////////////////
    //For Decryption
    else if (choice == 2)
    {
        //Start at position 0 of the string unless it's empty and increment from there
        for(i = 0; message[i] != '\0'; ++i)
        {
            //current letter is current position of 'i'
           current = message[i];
            //if current character is between 'a' and 'z'
            if(current >= 'a' && current <= 'z')
            {
                //current character is changed to character key* places up from current character
                current = current - key;
                //in order to reset back to 'z'
                if(current < 'a')
                {
                    //simply move forward 26 characters and continue
                    current = current + 26;
                }
            
                //set character value to new value  from current position 
                message[i] = current;
            }

            //FOR CAPITAL CHARACTERS (same as above)
            else if(current >= 'A' && current <= 'Z')
            {
                current = current + key;
            
                if(current < 'A')
                {
                    current = current + 26;
                }
            
                message[i] = current;
            }
        }
    
        //print encrypted  or decrypted output to user
        printf ("Your new message is: %s", message);
    
        return (0);
    }

    //error
    if (choice != 1 || 2)
    {
        return (0);
    }
}//(end)