import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class MorseCode extends JFrame{

    final static char alphanumerics[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S',
                                         'T','U','V','W','X','Y','Z'};
    final static String morse_alphanumerics[] = {"-----","*----","**---","***--","****-","*****","-****","--****","---**","----*","*-","-***","-*-*","-**",
                                                 "*","**-*","--*","****","**","*---","-*-","*-**","--","-*","---","*--*","--*-","*-*","***","-","**-","***-",
                                                 "*--","-**-","-*--","--**"};

    private TextField morseCodeOutput;
    private final JLabel morseCodeOutputLabel;

    private final TextField englishInput;
    private final JLabel englishInputLabel;

    private final TextField morseCodeInput;
    private final JLabel morseCodeInputLabel;
    private final JLabel englishOutputQMarkNote;
    private final JLabel spacingWarning;

    private TextField englishOutput;
    private final JLabel englishOutputLabel;

    private class EnglishHandler implements ActionListener
    {
        @Override
        public void actionPerformed(ActionEvent event)
        {
            String rawinput = englishInput.getText();
            String input = "";

            for (int i = 0; i < rawinput.length(); i++)
            {
                if (rawinput.charAt(i) > 96 && rawinput.charAt(i) < 123) //If the user entered a lowercase letter
                {                                          //it will be capitalized for the program to translate
                    input = input + (char)(rawinput.charAt(i) - 32);
                }
                else if (rawinput.charAt(i) == ' ' || (rawinput.charAt(i) > 47 && rawinput.charAt(i) < 58) || (rawinput.charAt(i) > 64 && rawinput.charAt(i) < 91))
                {                                                         //If the given character is already an uppercase letter, number,
                    input = input + rawinput.charAt(i);                          //or space, then it is included in the 'input' String as-is
                }
                else //If the user's input contains a special character, a message will print saying that special characters are not allowed
                {
                    morseCodeOutput.setColumns(40);
                    morseCodeOutput.setText("Only letters and numbers can be entered.");
                    return;
                }
            }


            String output = "";
            for (int i = 0; i < input.length(); i++)
            {
                for (int k = 0; k < alphanumerics.length; k++)
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

            morseCodeOutput.setText(output);
        }
    }

    private class MorseHandler implements ActionListener
    {
        @Override
        public void actionPerformed(ActionEvent event)
        {
            String current_letter = "";
            String output = "";
            String morse_message = morseCodeInput.getText();

            ArrayList<String> morse_parsed = new ArrayList<>();

            if (!morse_message.endsWith(" ")) //Add a space to the end of the Morse input if there isn't one.
            {                                 //This helps the rest of the event handler work properly.
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
                else
                {
                    if (current_letter.equals(" ") && morse_message.charAt(i) != ' ')
                    {
                        current_letter = String.valueOf(morse_message.charAt(i));
                    }
                    else
                    {
                        current_letter = current_letter + morse_message.charAt(i);
                    }

                }
            }


            Boolean spacing_issues = false;
            for (int i = 0; i < morse_parsed.size(); i++)
            {
                if (morse_parsed.get(i).equals(" "))
                {
                    output = output + " ";
                }
                else
                {
                    Boolean found_already = false;
                    for (int k = 0; k < morse_alphanumerics.length; k++)
                    {
                        if (morse_parsed.get(i).equals(morse_alphanumerics[k]))
                        {
                            output = output + alphanumerics[k];
                            found_already = true;
                        }
                        else if (found_already == false && k == 35 && !(morse_parsed.get(i).equals(alphanumerics[35])))
                        {
                            output = output + '?';

                            if (morse_parsed.get(i).charAt(0) == ' ' && !morse_parsed.get(i).endsWith(" "))
                            {
                                spacing_issues = true;
                            }
                        }
                    }
                }
            }

            if (spacing_issues)
            {
                spacingWarning.setVisible(true);
            }
            else
            {
                spacingWarning.setVisible(false);
            }

            Boolean is_qmark = false;
            for (int i = 0; i <output.length(); i++)
            {
                if (output.charAt(i) == '?')
                {
                    is_qmark = true;
                }
            }
            if (is_qmark)
            {
                englishOutputQMarkNote.setVisible(true);
            }
            else
            {
                englishOutputQMarkNote.setVisible(false);
            }

            englishOutput.setText(output);
        }
    }

    MorseCode()
    {
        super("Morse Code");



        englishInput = new TextField(10);
        englishInput.addActionListener(new EnglishHandler());
        englishInputLabel = new JLabel("English input: ");


        add(englishInputLabel);
        add(englishInput);

        morseCodeOutput = new TextField("Test", 50);
        morseCodeOutput.setEditable(false);
        morseCodeOutputLabel = new JLabel("\nMorse Code output: ");

        add(morseCodeOutputLabel);
        add(morseCodeOutput);

        morseCodeInput = new TextField(10);
        morseCodeInput.addActionListener(new MorseHandler());
        morseCodeInputLabel = new JLabel("Morse input: ");

        add(morseCodeInputLabel);
        add(morseCodeInput);


        englishOutput = new TextField(50);
        englishOutput.setEditable(false);
        englishOutputLabel = new JLabel("English output: ");

        add(englishOutputLabel);
        add(englishOutput);

        englishOutputQMarkNote = new JLabel("'?' denotes an unrecognized Morse character");

        add(englishOutputQMarkNote);
        englishOutputQMarkNote.setVisible(false);

        spacingWarning = new JLabel("Please check your spacing. Only single spaces ' ' and triple spaces '   ' are allowed.");
        add(spacingWarning);
        spacingWarning.setVisible(false);


        FlowLayout layout = new FlowLayout();
        setLayout(layout);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(775,175);
        setVisible(true);
    }
}