/**
 *  Derived from 'Questionnaire', this class asks a fill-in-the-blank question.
 *
 *  @author Austin Piper <austin-piper@uiowa.edu></austin-piper@uiowa.edu>
 *  @version 1.0
 *  @see Questionnaire
 *  @since 2/27/2021
 */
public class FillInTheBlanks extends Questionnaire
{

    /**
     * Where the (possibly multiple) responses to the question will be stored
     */
    private String[] responses;

    /**
     * The constructor receives and sets the question to be asked (as a String), as well as the amount of blanks expected to be filled.
     *
     * @param input_question The question to be asked
     * @param amount_of_blanks The amount of blanks expected to be filled
     */
    FillInTheBlanks(String input_question, int amount_of_blanks)
    {
        super("Please fill in the blanks. Put all of your answers onto one line, separating each by a semicolon.", input_question);

        responses = new String[amount_of_blanks];


        for (int i = 0; i < amount_of_blanks; i++)
        {
            setQuestion(getQuestion() + "\n" + String.valueOf(i+1) + "......");
        }
    }

    /***
     * Obtains the responses to the question from an outside source (typically a user). The user is supposed to
     * put every the answers to each blank all into one String--each answer separated by a semicolon.
     *
     * @param input_response The response to the question in String form.
     */
    @Override
    public void obtainResponse(String input_response)
    {
        int index = 0;

        String temp_string = "";

        for (int i = 0; i < input_response.length(); i++)
        {

            if (input_response.charAt(i) == ';')
            {
                if ((index + 1) > responses.length)
                {
                    throw new ArrayIndexOutOfBoundsException("More responses to the FillInTheBlank question were given than queries.");
                }
                responses[index] = temp_string;
                temp_string = "";
                index += 1;
            }
            else if ((i + 1) == input_response.length())
            {
                if ((index + 1) > responses.length)
                {
                    throw new ArrayIndexOutOfBoundsException("More responses to the FillInTheBlank question were given than queries.");
                }
                temp_string = temp_string + input_response.charAt(i);
                responses[index] = temp_string;
            }
            else
            {
                temp_string = temp_string + input_response.charAt(i);
            }
        }

        for (int i = 0; i < responses.length; i++)
        {
            if (responses[i] == "" || responses[i] == null)
            {
                responses[i] = "*No Response Given*";
            }
        }
    }

    /**
     * Returns the responses given (if any) in String form
     *
     * @return The responses given to the question in String format
     */
    @Override
    public String showResponse()
    {
        String string_form = "";

        for (int i = 0; i < responses.length; i++)
        {
            string_form = string_form + " " + String.valueOf(i+1)+". " + responses[i];
        }

        return string_form;
    }

}
