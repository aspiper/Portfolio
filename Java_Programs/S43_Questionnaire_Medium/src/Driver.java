/**
 * The driver is used to showcase Questionnaire-based objects, as well as QuestionPublisher in action.
 *
 *  @author Austin Piper <austin-piper@uiowa.edu></austin-piper@uiowa.edu>
 *  @version 1.0
 *  @see Questionnaire
 *  @since 2/27/2021
 */
public class Driver {

    /**
     * The body of code which is executed when Driver is run
     *
     * @param args
     */
    public static void main(String[] args)
    {
        Questionnaire q1 = new ShortAnswer("Who has the best eyebrows?");

        String[] choices = {"Black bear", "Panda Bear", "Grizzly Bear","Koala Bear"};
        Questionnaire q2 = new MultipleChoice("Which of the following is best?", choices);

        Questionnaire q3 = new FillInTheBlanks("My favorite song by The Who is ....., " +
                "and the color of the sky is .....  .",2);

        QuestionPublisher.questionPublish(q1);

        QuestionPublisher.questionPublish(q2);

        QuestionPublisher.questionPublish(q3);

        QuestionPublisher.seeAnswer(q1);
        QuestionPublisher.seeAnswer(q2);
        QuestionPublisher.seeAnswer(q3);
    }
}
