import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.IllegalFormatException;

public class BaseConverterGUI extends JFrame
{
    /**
     * The field in which the user enters a number to be converted
     */
    private final JTextField inputtedNumber;

    /**
     * A GUI label describing what inputtedNumber does
     *
     * @see inputtedNumber
     */
    private final JLabel inputtedNumberLabel;

    /**
     * The field in which the user enters the base of the number in inputtedNumber. Bases 2 through 36 are allowed
     *
     * @see inputtedNumber
     */
    private final JTextField currentBase;

    /**
     * A GUI label describing what currentBase does
     *
     * @see currentBase
     */
    private final JLabel currentBaseLabel;

    /**
     * The field in which the user enters the base to translate inputtedNumber to
     *
     * @see inputtedNumber
     */
    private final JTextField desiredBase;

    /**
     * A GUI label describing what desiredBase does
     *
     * @see desiredBase
     */
    private final JLabel desiredBaseLabel;

    /**
     * An uneditable field which displays the final, converted result
     */
    private final JTextField convertedNumber;

    /**
     * A GUI label describing what convertedNumber does
     */
    private final JLabel convertedNumberLabel;

    /**
     * A GUI button which calculates the information from the GUI when clicked
     */
    private final JButton submitButton;

    /**
     * A warning label that appears to the user when the user gives the program an invalid starting base
     *
     * @see currentBase
     */
    private final JLabel invalidStartingBase;

    /**
     * A warning label that appears to the user when the user gives the program an invalid final base
     *
     * @see desiredBase
     */
    private final JLabel invalidFinalBase;

    /**
     * A warning label that appears to the user if the user gives an invalid input number
     *
     * @see inputtedNumber
     */
    private final JLabel invalidInputNumber;

    /**
     * A warning label that appears to the user if at least one of the GUI's input boxes is empty
     *
     * @see inputtedNumber
     * @see currentBase
     * @see desiredBase
     */
    private final JLabel emptyInputBoxWarning;


    /**
     * Initializes an instance of the base converter GUI window
     */
    public BaseConverterGUI()
    {
        super("Base Converter");

        inputtedNumber = new JTextField(10);
        inputtedNumberLabel = new JLabel("Number to convert: ");

        currentBase = new JTextField(10);
        currentBaseLabel = new JLabel("Initial base:");

        desiredBase = new JTextField(10);
        desiredBaseLabel = new JLabel("Base to convert to: ");

        convertedNumber = new JTextField(10);
        convertedNumber.setEditable(false);

        convertedNumberLabel = new JLabel("Converted number: ");

        submitButton = new JButton("Submit");

        invalidStartingBase = new JLabel("Your initial base must be a value between 2 and 36.");
        invalidStartingBase.setVisible(false); //This JLabel should only show when the user causes a handled exception

        invalidFinalBase = new JLabel("Your final base must be an integer between 2 and 36");
        invalidFinalBase.setVisible(false); //This JLabel should only show when the user causes a handled exception

        invalidInputNumber = new JLabel("Your starting number is in a non-standard format for your given input base.");
        invalidInputNumber.setVisible(false); //This JLabel should only show when the user causes a handled exception

        emptyInputBoxWarning = new JLabel("At least one input box is missing information.");
        emptyInputBoxWarning.setVisible(false); //This JLabel should only show when the user causes a handled exception

        add(inputtedNumberLabel);
        add(inputtedNumber);

        add(currentBaseLabel);
        add(currentBase);

        add(desiredBaseLabel);
        add(desiredBase);

        add(submitButton);
        submitButton.addActionListener(
                new ActionListener()
                {
                    @Override
                    public void actionPerformed(ActionEvent e)
                    {
                        //Reset all GUI error messages
                        invalidStartingBase.setVisible(false);
                        invalidFinalBase.setVisible(false);
                        invalidInputNumber.setVisible(false);
                        emptyInputBoxWarning.setVisible(false);

                        if (inputtedNumber.getText().equals("") || currentBase.getText().equals("") || desiredBase.getText().equals(""))
                        {
                            emptyInputBoxWarning.setVisible(true);
                            return;
                        }

                        String output = new String();

                        int intermediate_value;

                        try
                        {
                            intermediate_value = Conversions.toDecimal(inputtedNumber.getText(), Integer.valueOf(currentBase.getText()));

                        }
                        catch (IllegalArgumentException f)
                        {
                            invalidStartingBase.setVisible(true);
                            convertedNumber.setText("Invalid");
                            return;
                        }
                        catch (NotInBaseException f)
                        {
                            invalidInputNumber.setVisible(true);
                            convertedNumber.setText("Invalid");
                            return;
                        }

                        try
                        {
                            output = Conversions.decimalToBase(intermediate_value, Integer.valueOf(desiredBase.getText()));
                        }
                        catch (IllegalArgumentException g)
                        {
                            invalidFinalBase.setVisible(true);
                            convertedNumber.setText("Invalid");
                        }

                        convertedNumber.setText(output);
                    }
                }
        );

        add(convertedNumberLabel);
        add(convertedNumber);

        add(invalidStartingBase);

        add(invalidFinalBase);

        add(invalidInputNumber);

        add(emptyInputBoxWarning);

        FlowLayout layout = new FlowLayout();
        setLayout(layout);

        setSize(750,200);
    }

}
