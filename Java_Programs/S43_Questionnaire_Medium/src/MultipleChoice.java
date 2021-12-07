/**
 *  Derived from 'Questionnaire', the MultipleChoice class will ask a multiple-choice question, and store a given
 *  answer as an integer.
 *
 *  @author Austin Piper <austin-piper@uiowa.edu></austin-piper@uiowa.edu>
 *  @version 1.0
 *  @see Questionnaire
 *  @since 2/27/2021
 *
 */
public class MultipleChoice extends Questionnaire {

    /**
     * The response to a MultipleChoice question is stored as an integer. This is so that numerical calculations
     * can be done with MultipleChoice questions if desired.
     */
    private int response;

    /**
     * This array contains all of the given options for a MultipleChoiceQuestion
     */
    private String[] options;

    /**
     * The constructor receives and sets the question to be asked (as a String), as well as the possible options to choose from (as a String array),
     *
     * @param input_question The question to be asked
     * @param input_options The possible options given for the question
     */
    MultipleChoice(String input_question,String input_options[])
    {
        super("Select one from the following.", input_question);

        options = input_options;

        String question_with_answers;

        for (int i = 0; i < input_options.length; i++)
        {
            setQuestion(getQuestion() + "\n" + String.valueOf(i + 1) + ". " + input_options[i]);
        }
    }

    /**
     * @param input_response The answer given to the question (typically by a user)
     *
     * @exception IllegalArgumentException An exception will be thrown if the given response cannot be converted into a
     *                                     positive integer. Note that it is still possible to give a response that does not correspond
     *                                     to a given answer (for instance, responding with '5' even though the question only has 4 options).
     *                                     This is intentional, because an irregular answer may still prove useful to a survey-giver
     */
    @Override
    public void obtainResponse(String input_response)
    {
        for (int i = 0; i < input_response.length(); i++)
        {
            if (!(input_response.charAt(i) > 48 && input_response.charAt(i) < 58))
            {
                throw new IllegalArgumentException("For a multiple choice question, the response given must be convertible into a positive integer");
            }
        }
        response = Integer.parseInt(input_response);
    }

    /**
     * Returns the value of 'response' in String format
     * @return The value of the 'response' integer in String form
     */
    @Override
    public String showResponse()
    {
        return String.valueOf(response);
    }

}
