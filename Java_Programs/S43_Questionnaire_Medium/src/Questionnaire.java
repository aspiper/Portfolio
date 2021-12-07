/**
 *  This is the base class which is the framework for all of the other question classes derived from it.
 *  Because the Questionnaire class is abstract, it cannot be instantiated directly.
 *
 * @author Austin Piper <austin-piper@uiowa.edu></austin-piper@uiowa.edu>
 * @version 1.0
 * @since 2/27/2021
 */
public abstract class Questionnaire {

    /**
     * Keeps track of how many Questionnaire-derived objects have been created. It is used to assign each question
     * within a program run-through a unique number.
     */
    private static int question_amount;

    /**
     * Represents what question number the current question object is.
     */
    private int question_number;

    /**
     * A String that introduces the question and says what kind of response is expected. Question intros are hard-coded
     * and pre-set according to the Questionnaire subclass type.
     */
    private String question_intro;

    /**
     * This contains the actual question (in words) that is to be answered.
     */
    private String question;


    /**
     *  The Questionnaire constructor sets the question being asked, as well as its introduction according to given inputs.
     *  This constructor is only ever called by its subclass' constructors.
     *
     * @param input_question_intro The introduction explaining how to answer the question. This string is typically hard-coded
     *                             into each subclass' constructor.
     * @param input_question        The question which is going to be asked in String form
     */
    Questionnaire(String input_question_intro, String input_question)
    {
        question_amount += 1;
        question_number = question_amount;

        question_intro = input_question_intro;
        question = input_question;

    }

    /**
     *  Returns the question's introduction as a String
     * @return The predefined intro to the current Questionnaire as a String
     */
    public String getQuestion_intro()
    {
        return question_intro;
    }

    /**
     *
     * @return The actual question that is going to be asked in String form.
     */
    public String getQuestion()
    {
        return question;
    }

    /**
     *  This method sets the contents of the 'question' String. It is intended for use within subclass methods only.
     *  Subclasses may use this to better format the question for presentation.
     *
     *  It is intentionally protected because giving outside clients access to it could unpredictably cause confusion.
     *  For example, if an outside client changes the contents of a question, but kept the already-given responses the same.
     *
     * @param new_question What the given question will become
     */
    protected void setQuestion(String new_question)
    {
        question = new_question;
    }

    /**
     *
     * @return The number that the question is within the current survey
     */
    public int getQuestionNumber()
    {
        return question_number;
    }


    /**
     * This abstract method is implemented differently by each subclass, and stores a given answer as appropriate.
     *
     * @param input_response The response to the question in String form.
     */
    public abstract void obtainResponse(String input_response);

    /**
     * This abstract method is implemented differently by each subclass, and returns the response received (if there is one)
     * in String form
     *
     * @return the question's response in String form
     */
    public abstract String showResponse();
}
