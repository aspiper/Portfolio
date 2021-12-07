import java.util.Random;

/**
 * This class takes a message in String form, and creates a new encrypted version of the original, as well as
 * its corresponding key.
 *
 * Note that there is no written constructor for this object, so it must be created without arguments.
 *
 * @author Austin Piper <austin-piper@uiowa.edu></austin-piper@uiowa.edu>
 * @version 2.0
 * @since 2021-02-14
 */
public class Encryptor {
    /**
     * The object refers to this alphabet array when encrypting a message
     */
    final static char alphabet[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    /**
     * This is where the Encryptor will store the message in encrypted form.
     */
    private String encrypted_message;

    /**
     * This is where the Encryptor will store its generated key.
     */
    private String key;

    Encryptor()
    {
        encrypted_message = "";
        key = "";
    }

    /**
     * This method takes a message in String form and creates a new String of the same message, but in a one-time
     * pad encryption. It then stores the encrypted message and its key within the src.Encryptor object.
     *
     * @param raw_message This is the message that is going to be decrypted
     */
    public void encrypt(String raw_message)
    {
        /*
         *  This method makes extensive use of the ASCII Table, so it would be beneficial to have a copy in front
         *  of you when analyzing/editing this method.
         */

        Random random_int = new Random();

        int n; //This is what the value of n at a particular letter will be
        char current_character;


        for (int i = 0; i < raw_message.length(); i++)
        {
            current_character = raw_message.charAt(i);

            n = random_int.nextInt(54) - 26; //n is a random number between -26 and 26


            if (current_character > 96 && current_character < 123) //Convert lowercase letters into uppercase
            {
                current_character -= 32;
            }

            if (current_character > 64 && current_character < 91 ) //If current_character is an uppercase letter
            {
                if (current_character + n < 91 && current_character + n > 64) //If current_character + n is still in the alphabet
                {
                    current_character = (char) (current_character + n);
                }
                else if (current_character + n > 90) //If current_character + n goes past the uppercase letters in the ASCII Table
                {
                    current_character = (char) ((((current_character - 64) + n) % 26) + 64);

                    if (current_character == 64)
                    {
                        current_character = (char) 90; //The statement above mistakenly outputs '@' instead of 'Z'. This statement corrects that.
                    }
                }
                else if (current_character + n < 65) //If current_character + n goes below the uppercase letters in the ASCII Table
                {
                    current_character = (char) ((((current_character - 64) + n) % 26) + 90);
                }

            }

            int index = current_character - 65; //This represents current_character an index of the alphabet char array


            if (index >= 0 && index <= 25) //Add uppercase letter according to alphabet array index if current_character is an uppercase letter
            {
                key = key + String.valueOf(n) + " "; //Append current n-value to key
                encrypted_message = encrypted_message + alphabet[index];
            }
            else //If current_character is not an uppercase letter and not part of the alphabet array, then add
            {    // current_character to the encrypted message as-is.

                encrypted_message = encrypted_message + current_character;
            }
        }
    }

    /**
     * This method returns the object's stored encrypted message as a String.
     */
    public String getEncryptedMessage()
    {
        return encrypted_message;
    }

    /**
     * This returns the generated key (if there is one) as a String
     *
     * @return Returns the generated key as a String
     */
    public String getKey()
    {
        return key;
    }
}
