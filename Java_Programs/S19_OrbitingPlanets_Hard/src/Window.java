import javax.swing.*;
import java.awt.*;

/**
 *  This class contains the GUI window that will house the Solar System JPanel.
 *
 * @author Austin Piper <austin-piper@uiowa.edu></austin-piper@uiowa.edu>
 * @version 1.0
 * @since 3/28/2021
 */
public class Window extends JFrame
{
    /**
     * The part of the 'Window' JFrame that contains the simulates solar system
     */
    public SolarSystemPanel panel;

    /**
     *  Creates an instance of Window which contains a solar system simulation
     *
     * @param title The title of the GUI window
     */
    public Window(String title)
    {
        super(title);
        panel = new SolarSystemPanel();
        setSize(2000,2000);
        add(panel);

        panel.setVisible(true);
    }
}
