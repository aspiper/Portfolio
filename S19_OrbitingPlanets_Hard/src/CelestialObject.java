import static java.lang.Math.sin;
import static java.lang.Math.cos;

/**
 *  This abstract class forms the basis of each celestial body that will appear in the solar system simulation.
 *  Each instance of CelestialObject is governed by its own separate processor thread through the Runnable interface.
 *
 * @author Austin Piper <austin-piper@uiowa.edu></austin-piper@uiowa.edu>
 * @version 1.0
 * @since 3/28/2021
 */
public abstract class CelestialObject implements Runnable
{

    /**
     * The size of the CelestialObject within space
     */
    private final int radius;

    /**
     * The current x-position of the CelestialObject within space
     */
    private int x;

    /**
     * The current y-position of the CelestialObject within space
     */
    private int y;

    /**
     * Creates an instance of CelestialObject. Because CelestialObject is abstract, this constructor can only
     * be called from a subclass' constructor.
     *
     * @param input_radius The size of the new CelestialObject within space
     * @param input_x The beginning x-position of the CelestialObject within space
     * @param input_y The beginning y-position of the CelestialObject within space
     */
    public CelestialObject(int input_radius, int input_x, int input_y)
    {
        radius = input_radius;

        x = input_x;
        y = input_y;

    }

    /**
     * When a CelestialObject is executed in a thread, it will continually update its position within space
     * every 100 milliseconds.
     */
    @Override
    public void run()
    {
        while (true) //The Celestial Object will continuously update throughout the program's execution
        {
            update(); //Each subclass' 'update' function will be unique

            try
            {
                Thread.sleep(100); //After a CelestialObject has updated, it wil rest for 100 milliseconds
            }
            catch (Exception exception)
            {

            }

        }
    }

    /**
     * Used by subclasses to define how the CelestialObject moves within space
     */
    public abstract void update();

    /**
     * Returns the x and y coordinates of the CelestialObject as an array [x, y]. This method is synchronized, so both x and y
     * coordinates are guaranteed to correspond to each other.
     *
     * @return An array containing the [x, y] coordinates of the CelestialObject
     */
    public synchronized int[] getCoordinates()
    {
        int[] coordinates = {x , y};
        return coordinates;
    }

    /**
     * Returns the radius of the CelestialObject in 2D space
     *
     * @return The physical radius of the CelestialObject in 2D space
     */
    public int getRadius()
    {
        return radius;
    }

    /**
     * Returns the current x-coordinate of the current CelestialObject. This method is NOT SYNCHRONIZED, and should
     * be used sparingly. Otherwise, there is a risk of it returning an x-coordinate which does not accurately
     * correspond to a given y-coordinate. To obtain a synchronized set of x and y coordinates, use the getCoordinates()
     * method.
     *
     *
     * @see getCoordinates()
     * @return The CelestialObject's current x-coordinate within 2D space
     */
    protected int getX()
    {
        return x;
    }

    /**
     * Sets the x-coordinate of the current CelestialObject. Is used primarily within subclass update() methods.
     * Using this method on its own may cause unpredictable behavior, and is not recommended.
     *
     * @param new_x The new x-coordinate for the CelestialObject
     */
    protected void setX(int new_x)
    {
        x = new_x;
    }

    /**
     * Returns the current y-coordinate of the current CelestialObject. This method is NOT SYNCHRONIZED, and should
     * be used sparingly. Otherwise, there is a risk of it returning a y-coordinate which does not accurately
     * correspond to a given x-coordinate. To obtain a synchronized set of x and y coordinates, use the getCoordinates()
     * method.
     *
     *
     * @see getCoordinates()
     * @return The CelestialObject's current y-coordinate within 2D space
     */
    protected int getY()
    {
        return y;
    }

    /**
     * Sets the y-coordinate of the current CelestialObject. Is used primarily within subclass update() methods.
     * Using this method on its own may cause unpredictable behavior, and is not recommended.
     *
     * @param new_y The new y-coordinate for the CelestialObject
     */
    protected void setY(int new_y)
    {
        y = new_y;
    }
}
