import javax.swing.*;

/**
 * Creates a Window instance, which contains a demonstration of SolarSystemPanel
 *
 * @author Austin Piper <austin-piper@uiowa.edu></austin-piper@uiowa.edu>
 * @version 1.0
 * @since 4/4/2021
 */
public class Driver {

    /**
     * Initializes a Window object
     *
     * @param args
     */
    public static void main(String args[])
    {
        Window driverWindow = new Window("Solar System");
        driverWindow.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        driverWindow.setVisible(true);
        
        
    }
}
