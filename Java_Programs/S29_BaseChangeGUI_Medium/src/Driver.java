import javax.swing.*;

/**
 *  Runs an instance of BaseConverterGUI
 *
 * @author Austin Piper <austin-piper@uiowa.edu></austin-piper@uiowa.edu>
 * @version 1.0
 * @since 4/5/2021
 */
public class Driver {

    /**
     * Runs an instance of BaseConverterGUI
     * @param args
     */
    public static void main(String args[])
    {
        BaseConverterGUI window = new BaseConverterGUI();

        window.setVisible(true);
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }

}
