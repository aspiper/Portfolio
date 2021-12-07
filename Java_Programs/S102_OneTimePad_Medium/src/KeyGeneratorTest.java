import java.util.Scanner;

/**
 * This class is a driver used to give an idea of how Encryptor and Decryptor work. It runs through a typical use of Encryptor,
 * and then a typical use of Decryptor.
 *
 * @author Austin Piper <austin-piper@uiowa.edu></austin-piper@uiowa.edu>
 * @version 2.1
 * @since 2021-02-14
 */
public class KeyGeneratorTest {
    // main method begins execution of Java application
    /**
     * This tests Encryptor and Decryptor objects using keyboard-based inputs.
     *
     * @param args
     */
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        Encryptor encrypt = new Encryptor();

        System.out.printf("%s", "Please enter a message to be encrypted: ");
        encrypt.encrypt(input.nextLine());

        System.out.printf("%s%n", "\nYour key is: " + encrypt.getKey());
        System.out.printf("%n%s%n", "Your message in encrypted form is: " + encrypt.getEncryptedMessage());

        //Decryption begins
        Decryptor decrypt = new Decryptor();

        System.out.printf("%s", "\n\n\nPlease enter the key that accompanies your message (be sure to include a single space between each number): ");
        decrypt.setKey(input.nextLine());

        System.out.printf("%s", "Please enter a message to be decrypted: ");
        decrypt.decrypt(input.nextLine());

        System.out.printf("%s%n", "\nYour message in decrypted form is: " + decrypt.getDecryptedMessage());





    } // end method main
}
