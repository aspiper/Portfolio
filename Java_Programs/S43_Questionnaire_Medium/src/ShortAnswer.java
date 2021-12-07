/**
 *  Derived from 'Questionnaire', a ShortAnswer object will ask for a short response to a given question, then store
 *  a given answer as a String.
 *
 *  @author Austin Piper <austin-piper@uiowa.edu></austin-piper@uiowa.edu>
 *  @version 1.0
 *  @see Questionnaire
 *  @since 2/27/2021
 */
public class ShortAnswer extends Questionnaire
{
    /**
     * The user's response to the question is stored here.
     */
    private String response;

    /**
     * The ShortAnswer constructor takes a String as input, and passes that on to the Questionnaire constructor,
     * which sets that String as the question being asked.
     *
     * @param input_question The question which will be asked by the object
     */
    ShortAnswer(String input_question)
    {
        super("Please give a short answer.", input_question);
    }


    /**
     * Gets a response to the question from an outside source (typically a user)
     *
     * @param input_response The response to the question in String form.
     */
    @Override
    public void obtainResponse(String input_response)
    {
        response = input_response;
    }

    /**
     * Shows the recorded response to the question (if there is one)
     *
     * @return The response to the object's question
     */
    @Override
    public String showResponse()
    {
        return response;
    }
}
