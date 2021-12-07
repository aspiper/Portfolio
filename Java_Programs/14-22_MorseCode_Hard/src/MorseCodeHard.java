import javax.swing.*;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import java.awt.*;
import java.util.ArrayList;

/**
 *  This class contains all that is needed for the Morse Code translator. As soon as an instance is created,
 *  the translator's GUI will appear and be ready to use.
 *
 * @author Austin Piper <austin-piper@uiowa.edu></austin-piper@uiowa.edu>
 * @version 1.0
 * @since 3/6/2021
 */
public class MorseCodeHard extends JFrame{

    /**
     * An array which contains each numeral and alphabetical character. Used as a reference by the program when translating
     */
    final static char alphanumerics[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S',
                                         'T','U','V','W','X','Y','Z'};

    /**
     * An array which contains each numeral and alphabetical character in Morse Code. Used as a reference by the program when translating
     */
    final static String morse_alphanumerics[] = {"-----","*----","**---","***--","****-","*****","-****","--****","---**","----*","*-","-***","-*-*","-**",
                                                 "*","**-*","--*","****","**","*---","-*-","*-**","--","-*","---","*--*","--*-","*-*","***","-","**-","***-",
                                                 "*--","-**-","-*--","--**"};


    /**
     * The text field where English input and/or output will go.
     *
     * If this field detects a change in its contents by the user, its document handler will call a function which
     * translates its contents into Morse Code.
     *
     * @see toMorse
     */
    private final JTextField english;

    /**
     * JLabel signifying which JTextField is the English one
     *
     * @see english
     */
    private final JLabel englishLabel;

    /**
     * The text field where Morse Code input and/or output will go.
     *
     * If this field detects a change in its contents by the user, its document handler will call a function which
     * translates its contents into English (this translation is displayed in the Morse Code JTextField).
     *
     * @see toEnglish
     */
    private final JTextField morseCode;

    /**
     * JLabel signifying which JTextField is the Morse Code one
     *
     * @see morseCode
     */
    private final JLabel morseCodeLabel;

    /**
     * JLabel telling the user what a '?' means when one appears in the Morse Code box
     */
    private final JLabel QMarkNote;

    /**
     * JLabel telling the user to check their spacing when their Morse Code spacing is incorrect
     */
    private final JLabel SpaceWarning;

    /**
     * JLabel which tells the user why their input is invalid, if it is.
     */
    private final JLabel Warning;


    /**
     * Instantiates the object and prepares the GUI
     */
    MorseCodeHard()
    {
        super("Morse Code");



        english = new JTextField(10);
        english.getDocument().addDocumentListener(new DocumentListener()
        {
            @Override
            public void insertUpdate(DocumentEvent documentEvent)
            {
                if (english.isFocusOwner()) //This is so that "to-Morse" translation is not done when the program (not the user)
                {                           //sends an output to this text field
                    morseCode.setText(toMorse(english.getText()));

                    QMarkNote.setVisible(false); //Hide any GUI warnings that the user may have triggered with an earlier
                    SpaceWarning.setVisible(false); //Morse-to-English translation
                }
            }

            @Override
            public void removeUpdate(DocumentEvent documentEvent)
            {
                if (english.isFocusOwner())
                {
                    morseCode.setText(toMorse(english.getText()));
                }
            }

            @Override
            public void changedUpdate(DocumentEvent documentEvent) //There is no use for this method, so its implementation is left blank
            {
            }
        });
        englishLabel = new JLabel("English: ");

        add(englishLabel);
        add(english);


        morseCode = new JTextField(10);
        morseCode.getDocument().addDocumentListener(new DocumentListener()
        {
            @Override
            public void insertUpdate(DocumentEvent documentEvent)
            {
                if (morseCode.isFocusOwner())//This is so that "to-English" translation is not done when the program (not the user)
                {                           //sends an output to this text field
                    english.setText(toEnglish(morseCode.getText()));
                }
            }

            @Override
            public void removeUpdate(DocumentEvent documentEvent)
            {
                if (morseCode.isFocusOwner())
                {
                    english.setText(toEnglish(morseCode.getText()));
                }
            }

            @Override
            public void changedUpdate(DocumentEvent documentEvent) //There is no use for this method, so its implementation is left blank
            {
            }
        });
        morseCodeLabel = new JLabel("Morse: ");

        add(morseCodeLabel);
        add(morseCode);


        QMarkNote = new JLabel("'?' denotes an unrecognized Morse character given");
        add(QMarkNote);
        QMarkNote.setVisible(false); //Will be turned on by other parts of the program as appropriate

        Warning = new JLabel();
        add(Warning);
        Warning.setVisible(false); //Will be turned on by other parts of the program as appropriate

        SpaceWarning = new JLabel("Please check your spacing. Only single spaces ' ' and triple spaces '   ' are allowed.");
        add(SpaceWarning);
        SpaceWarning.setVisible(false); //Will be turned on by other parts of the program as appropriate


        FlowLayout layout = new FlowLayout();
        setLayout(layout);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(700,175); //The values (700, 175) are what is needed for the GUI to look clean. It may become messy if these values are changed
        setVisible(true);
    }

    /**
     * Translates a String in English to a String in Morse Code. Will only work with numbers, letters, and spaces. Will return
     * a String that says "Invalid input" if the given input includes a special character (it will also tell the GUI to display
     * a message to the user as to why the input is invalid).
     *
     * @param rawinput The input that is to be translated. This is a String written in plain English
     * @return The Morse Code translation of the input in String form
     */
    private String toMorse(String rawinput)
    {
        String input = "";

        if (rawinput.equals("")) //Exit method early if there is nothing to translate
        {
            Warning.setVisible(false); //If the input is empty, then there is nothing to warn about
            return "";
        }

        for (int i = 0; i < rawinput.length(); i++)
        {
            if (rawinput.charAt(i) > 96 && rawinput.charAt(i) < 123) //If the user entered a lowercase letter
            {                                                        //it will be capitalized for the program to translate
                input = input + (char)(rawinput.charAt(i) - 32);
            }
            else if (rawinput.charAt(i) == ' ' || (rawinput.charAt(i) > 47 && rawinput.charAt(i) < 58) || (rawinput.charAt(i) > 64 && rawinput.charAt(i) < 91))
            {                                                                //If the given character is already an uppercase letter, number,
                input = input + rawinput.charAt(i);                          //or space, then it is included in the 'input' String as-is
            }
            else //If the user's input contains a special character, a message will print saying that special characters are not allowed
            {   //The method will also leave early
                Warning.setText("Only letters, numbers, and spaces can be entered in the English box");
                Warning.setVisible(true);
                return "Invalid input";
            }
        }

        String output = "";
        for (int i = 0; i < input.length(); i++)
        {
            for (int k = 0; k < alphanumerics.length; k++) //This loop will always run 36 times in total
            {
                if (input.charAt(i) == alphanumerics[k])
                {
                    output = output + morse_alphanumerics[k] + ' ';
                }
            }

            if (input.charAt(i) == ' ')
            {
                output = output + "   ";
            }
        }
        Warning.setVisible(false); //If the method has made it this far, then the input must have been valid, so the input warning disappears
        return output;
    }


    /**
     * Translates a String in Morse Code to a String in English. Will only work with numbers, letters,
     * and spaces (in Morse Code format). Will return a String which says 'Invalid input' if it is given
     * an input which contains characters other than '*', '-', or spaces ' '. However, it will continue
     * past Morse Code-format characters that it doesn't recognize, leaving a '?' where the translated
     * character otherwise would have gone.
     *
     *
     * @param morse_message The input that is to be translated. This is a String written in Morse Code
     * @return The English translation of the input in String form
     */
    private String toEnglish(String morse_message)
    {
        String current_letter = ""; //The current Morse letter being parsed
        String output = "";

        ArrayList<String> morse_parsed = new ArrayList<>(); //The input message is parsed into individual Morse characters
                                                            //and spaces. Those are kept in this ArrayList

        if (morse_message.equals("")) //Leave the method early if there is nothing to translate
        {
            return "";
        }

        if (!morse_message.endsWith(" ")) //Add a space to the end of the Morse input if there isn't one.
        {                                 //This helps the rest of the translation method work properly.
            morse_message += ' ';
        }

        for (int i = 0; i < morse_message.length(); i++)
        {
            if (morse_message.charAt(i) == ' ' && !current_letter.equals(" ") && !current_letter.equals("  ")) //If a letter break has been reached
            {
                morse_parsed.add(current_letter);

                current_letter = String.valueOf(morse_message.charAt(i));
            }
            else if (morse_message.charAt(i) == ' ' && current_letter.equals("  ")) //If a space has been reached
            {
                morse_parsed.add(" ");
                current_letter = "";
            }
            else //If the char at 'i' is part of a Morse character
            {
                if (morse_message.charAt(i) != '*' && morse_message.charAt(i) != '-' && morse_message.charAt(i) != ' ')
                {  //Ends the method early and has the GUI display an error message if the given input has an invalid character
                    Warning.setText("Only dashes '-', dots '*' and spaces ' ' can be entered in the Morse box.");
                    Warning.setVisible(true);
                    return "Invalid input";
                }
                if (current_letter.equals(" ") && morse_message.charAt(i) != ' ') //The translator may sometimes include a space
                {                                                                 //at the beginning of a parsed letter.
                    current_letter = String.valueOf(morse_message.charAt(i));     //This rectifies that issue.
                }
                else
                {
                    current_letter = current_letter + morse_message.charAt(i);
                }

            }
        }


        Boolean spacing_issues = false;
        for (int i = 0; i < morse_parsed.size(); i++) //Turning the parsed input into an English output
        {                                             //Also checks the input for program-manageable mistakes
            if (morse_parsed.get(i).equals(" "))
            {
                output = output + " ";
            }
            else
            {
                Boolean found_already = false;
                for (int k = 0; k < morse_alphanumerics.length; k++) //Compares the current Morse letter to the Morse alphanumericals.
                {                                                    //Will loop exactly 36 times.
                    if (morse_parsed.get(i).equals(morse_alphanumerics[k]))
                    {
                        output = output + alphanumerics[k];
                        found_already = true;
                    }
                    else if (found_already == false && k == 35 && !(morse_parsed.get(i).equals(alphanumerics[35])))
                    {
                        output = output + '?'; //An unrecognized Morse character will be represented by a '?' in the English translation

                        if (morse_parsed.get(i).isEmpty() ||(morse_parsed.get(i).charAt(0) == ' ' && !morse_parsed.get(i).endsWith(" ")))
                        {
                            spacing_issues = true;
                        }
                    }
                }
            }
        }

        Warning.setVisible(false); //Becuase the given input is valid, the input validation warning disappears

        if (spacing_issues) //Has the GUI to display the SpaceWarning if the input has spacing issues
        {
            SpaceWarning.setVisible(true);
        }
        else //Hides the SpaceWaring if there are no spacing issues in the input
        {
            SpaceWarning.setVisible(false);
        }

        Boolean is_qmark = false;
        for (int i = 0; i <output.length(); i++) //Checks to see if there were any unrecognized Morse characters used
        {
            if (output.charAt(i) == '?')
            {
                is_qmark = true;
            }
        }
        if (is_qmark) //A message in the GUI appears explaining to the user what the '?' means, if it appears.
        {
            QMarkNote.setVisible(true);
        }
        else //Hides the GUI's QMarkNote if ther are no '?'s in the output
        {
            QMarkNote.setVisible(false);
        }

        return output;
    }

}