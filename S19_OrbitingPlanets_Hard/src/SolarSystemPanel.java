import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import java.util.concurrent.Executors;
import java.util.concurrent.ExecutorService;



/**
 *  This JPanel-derived class contains the implementation of a solar system simulation.
 *
 * @author Austin Piper <austin-piper@uiowa.edu></austin-piper@uiowa.edu>
 * @version 1.0
 * @since 3/28/2021
 */
public class SolarSystemPanel extends JPanel
{
    /**
     * Because each CelestialObject has its own thread, an ExecutorService is used to manage them.
     */
    private ExecutorService executorService;


    /**
     * Contains a reference to each CelestialObject that currently exists.
     */
    private ArrayList<CelestialObject> celestialObjects;

    /**
     * Contains a reference to each Planet that currently exists.
     */
    private ArrayList<Planet> planets;

    /**
     * Prompts the SolarSystemPanel to update on the screen every 50 milliseconds. The Timer's listener is implemented
     * in the SolarSystemPanel constructor.
     *
     * @see SolarSystemPanel constructor
     */
    private Timer refresh;


    /**
     * Creates an instance of a solar system simulation for implementation in a JFrame.
     */
    public SolarSystemPanel()
    {
        super();
        executorService = Executors.newCachedThreadPool();
        setSize(2000,2000);
        setFocusable(true);
        grabFocus(); //The JPanel needs focus for the KeyboardPressHandler to function

        refresh = new Timer(10, actionEvent -> repaint()); //The planets on the screen are redrawn every 10 milliseconds
        refresh.start();
        refresh.setRepeats(true);

        addMouseListener(new MouseClickHandler()); //See implementation in private class below
        addKeyListener(new KeyboardPressHandler()); //See implementation in private class below

        celestialObjects = new ArrayList<CelestialObject>();
        planets = new ArrayList<Planet>();


        CelestialObject firstPlanet = new Planet(30,950 + 75,1000 ,  3); //The solar system begins with a single orbiting planet
        celestialObjects.add(new Star(50,950,1000)); //The program begins with a planet orbiting a single star

        celestialObjects.add(firstPlanet);
        planets.add((Planet) firstPlanet);



        for (int i = 0; i < celestialObjects.size(); i++) //Each CelestialObject gets its own thread
        {
            executorService.execute(celestialObjects.get(i));
        }
    }

    /**
     * Paints the solar system simulation to the JPanel
     *
     * @param component Graphics component dealt with behind the scenes by Swing. A developer would likely not have to worry about this.
     */
    @Override
    public void paintComponent(Graphics component)
    {
        super.paintComponent(component);

        component.drawString("Click to add up to an additional 7 planets to this system." , 50,50);
        component.drawString("Press the number keys to add up to two moons per planet.", 50, 100);

        for (int i = 0; i < celestialObjects.size(); i++)
        {
            int body_coordinates[] = celestialObjects.get(i).getCoordinates();

            if (celestialObjects.get(i).getClass().getSimpleName() == "Star")
            {
                component.setColor(Color.YELLOW);
            }
            else if (celestialObjects.get(i).getClass().getSimpleName() == "Planet")
            {
                component.setColor(Color.BLACK);
            }
            else if (celestialObjects.get(i).getClass().getSimpleName() == "Moon")
            {
                component.setColor(Color.BLUE);
            }

            component.fillOval(body_coordinates[0], body_coordinates[1], celestialObjects.get(i).getRadius() , celestialObjects.get(i).getRadius() );
        }
    }

    /**
     * Adds a new planet to the solar system every time the mouse is clicked. This handler is implemented in the SolarSystemPanel constructor.
     *
     * @see SolarSystemPanel constructor
     */
    private class MouseClickHandler extends MouseAdapter
    {
        @Override
        public void mouseClicked(MouseEvent mouseEvent)
        {
            if (planets.size() < 8)
            {
                CelestialObject newPlanet = new Planet(30, 950 + 75 * celestialObjects.size(), 1000,  3 + 2 * planets.size());
                celestialObjects.add(newPlanet);
                planets.add((Planet) newPlanet);
                executorService.execute(newPlanet);
            }
        }

    }

    /**
     * Adds a new moon to a planet when the corresponding numerical key is pressed. i.e., the '2' key will give the
     * second planet in the solar system a moon. Each planet can have a maximum of 2 moons. The KeyboardPressHandler
     * is implemented in the SolarSystemPanel constructor
     *
     * @see Moon
     * @see SolarSystemPanel constructor
     */
    private class KeyboardPressHandler extends KeyAdapter
    {
        @Override
        public void keyPressed(KeyEvent e)
        {

            int number_pressed = -1;


            if (e.getKeyCode() == KeyEvent.VK_1)
            {
                number_pressed = 0; //This is used as an index to the 'planets' ArrayList. 0 corresponds to the first planet in the system
            }
            else if (e.getKeyCode() == KeyEvent.VK_2)
            {
                number_pressed = 1;
            }
            else if (e.getKeyCode() == KeyEvent.VK_3)
            {
                number_pressed = 2;
            }
            else if (e.getKeyCode() == KeyEvent.VK_4)
            {
                number_pressed = 3;
            }
            else if (e.getKeyCode() == KeyEvent.VK_5)
            {
                number_pressed = 4;
            }
            else if (e.getKeyCode() == KeyEvent.VK_6)
            {
                number_pressed = 5;
            }
            else if (e.getKeyCode() == KeyEvent.VK_7)
            {
                number_pressed = 6;
            }
            else if (e.getKeyCode() == KeyEvent.VK_8)
            {
                number_pressed = 7;
            }

            if (number_pressed >= 0 && number_pressed <= 7 && planets.size() >= (number_pressed + 1)) //If the number pressed corresponds
            {                                                                                   //to a currently-existing Planet
                if (planets.get(number_pressed).getMoonCount() < 2) //If the selected Planet has less than 2 moons
                {
                    CelestialObject newMoon = new Moon(planets.get(number_pressed), 10, 50 + 10 * planets.get(number_pressed).getMoonCount());
                    celestialObjects.add(newMoon);
                    executorService.execute(newMoon);

                    planets.get(number_pressed).addToMoonCount();
                }
            }
        }
    }

}
