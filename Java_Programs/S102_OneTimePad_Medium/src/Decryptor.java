/**
 * This class takes an encrypted message in String form and a corresponding key. It uses this key to decrypt the message. It then stores
 * the decrypted message within the object for future use or display.
 *
 *  @author Austin Piper <austin-piper@uiowa.edu></austin-piper@uiowa.edu>
 *  @version 2.1
 *  @since 2021-02-14
 */
public class Decryptor {

    /**
     * The object refers to this alphabet array when decrypting a message
     */
    final static char alphabet[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    /**
     * This is where the Decryptor will store its decrypted message.
     */
    private String decrypted_message;

    /**
     * This is where the Decryptor will store a key for use in 'decrypt'
     *
     * @see decrypt
     */
    private String key;

    /**
     * Because the object is based upon appending to 'decrypted_message' over time, decrypted_message must be set to
     * "" instead of the default 'null'
     *
     * @see decrypted_message
     */
    Decryptor()
    {
        decrypted_message = "";
    }


    /**
     * This method sets the key which will later be used to decrypt the message.
     * @param new_key This key will become the key used by the decryptor
     * @exception IllegalArgumentException An exception will occur if anything other than numbers, minus signs, or spaces
     *                                     appear in the key given
     */
    public void setKey(String new_key)
    {
        key = new_key + " "; /* The extra space is necessary because the decryptor specifically looks for spaces.
                              * If it wasn't there, then the decrypt method would start looking in unrelated parts of
                              * memory beyond the key string's scope, and cause an error. */

        for (int i = 0; i < key.length(); i++) //Check the key for invalid input
        {
            if (!(key.charAt(i) >= '0' && key.charAt(i) <= '9') && (key.charAt(i) != '-' && key.charAt(i) != ' '))
            {
                throw new IllegalArgumentException("A key must only contain numbers, minus signs '-' and spaces");
            }
        }
    }

    /**
     * This method takes an encrypted message in String form and creates a new String of the same message, but decrypted
     * (according to the key stored in the object). It then stores this new String.
     *
     * @param encrypted_message
     * @exception StringIndexOutOfBoundsException Will throw an exception if there are fewer
     *                                            integers in the key than alphabetical letters in the encrypted message
     */
    public void decrypt(String encrypted_message)
    {
        /*
         *  This method makes extensive use of the ASCII Table, so it would be beneficial to have a copy in front
         *  of you when analyzing/editing this method.
         */
        char current_character;
        String n_stringform;
        int key_position = 0; //This is the character in 'key' which is currently being analyzed
        int n;


        for(int i = 0; i < encrypted_message.length(); i++)
        {
            current_character = encrypted_message.charAt(i);

            if (current_character > 64 && current_character < 91)
            {
                n_stringform = ""; //This while loop gets the numerical value of the key at the current location
                while (key.charAt(key_position) != 32 && key.charAt(key_position) != 0) //While the current character
                {                                                                       //of key is neither a space nor null-character
                    n_stringform = n_stringform + key.charAt(key_position);

                    key_position += 1;
                }

                if (key.charAt(key_position) == 32) //Ignore spaces within the key
                {
                    key_position += 1;
                }


                n = Integer.parseInt(n_stringform);


                if (current_character - n < 91 && current_character - n > 64) //If current_character - n is still in the alphabet
                {
                    current_character = (char) (current_character - n);
                }
                else if (current_character - n > 90) //If current_character - n goes past the uppercase letters in the ASCII Table
                {
                    current_character = (char) ((((current_character - 64) - n) % 26) + 64);

                    if (current_character == 64)
                    {
                        current_character = (char) 90; //The statement above mistakenly outputs '@' instead of 'Z'. This statement corrects that.
                    }
                }
                else if (current_character - n < 65) //If current_character - n goes below the uppercase letters in the ASCII Table
                {
                    current_character = (char) ((((current_character - 64) - n) % 26) + 90);
                }
            }

            int index = current_character - 65; //This represents current_character an index of the alphabet char array

            if (index >= 0 && index <= 25)
            {
                decrypted_message = decrypted_message + alphabet[index];
            }
            else
            {
                decrypted_message = decrypted_message + current_character;
            }

        }
    }

    /**
     * This method returns the decrypted message as a String.
     */
    public String getDecryptedMessage()
    {
        return decrypted_message;
    }
}
