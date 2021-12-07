/**
 *  An exception that is to be thrown when a method in Conversions comes across a character that does not belong
 *  in the base that it is working with.
 *
 * @author Austin Piper <austin-piper@uiowa.edu></austin-piper@uiowa.edu>
 * @version 1.0
 * @see Conversions
 * @since 4/5/2021
 */
public class NotInBaseException extends RuntimeException
{
    /**
     * Instantiates the NotInBaseException
     */
    public NotInBaseException()
    {
        super("The given number includes a numeral that is not part of the given base");
    }
}
