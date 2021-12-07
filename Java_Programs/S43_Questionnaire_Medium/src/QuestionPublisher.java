import java.util.Scanner;

/**
 * QuestionPublisher is a vehicle for using the Questionnaire class (and its sub-classes). Its static methods are used to ask question
 * objects, and also to view any responses to them.
 *
 *  @author Austin Piper <austin-piper@uiowa.edu></austin-piper@uiowa.edu>
 *  @version 1.0
 *  @see Questionnaire
 *  @since 2/27/2021
 */
public abstract class QuestionPublisher {

    /**
     * Pushes a question to the user, and gets an answer or answers from the user. It stores the user's answer
     * within the question object.
     *
     * @param question The question which is being asked to the user (in object form)
     * @see Questionnaire
     */
    static void questionPublish(Questionnaire question)
    {
        System.out.println("\nQuestion #" + String.valueOf(question.getQuestionNumber()));
        System.out.println(question.getQuestion_intro());
        System.out.println(question.getQuestion());

        Scanner input = new Scanner(System.in);

        question.obtainResponse(input.nextLine());

    }

    /**
     * Takes the recorded answer/answers from a Questionnaire-derived object and displays it to the screen.
     * @param question The question from which the response is taken from
     */
    static void seeAnswer(Questionnaire question)
    {
        System.out.println("Answer(s) to Q#" + String.valueOf(question.getQuestionNumber()) +":");
        System.out.println(question.showResponse());
    }
}
