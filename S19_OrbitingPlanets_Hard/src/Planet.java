import static java.lang.Math.cos;
import static java.lang.Math.sin;


/**
 *  Derived from CelestialObject, a Planet has the added capability of having an orbit and a velocity.
 *
 * @author Austin Piper <austin-piper@uiowa.edu></austin-piper@uiowa.edu>
 * @version 1.0
 * @since 3/28/2021
 */
public class Planet extends CelestialObject
{
    /**
     * The radius of the Planet's orbital path
     */
    private int orbit_radius;

    /**
     * The amount of Moons that are currently orbiting this Planet. This is incremented every time the addToMoonCount
     * method is called on the object. With the standard implementation of KeyboardPressHandler (see SolarSystemPanel),
     * A maximum of 2 Moons can be associated with a Planet.
     *
     * @see SolarSystemPanel.KeyboardPressHandler
     * @see Moon
     */
    private int moons_orbiting_planet;

    /**
     * The Planet's velocity is determined using a set of parametric equations. This is the parametric variable.
     *
     * @see update
     */
    private int t;

    /**
     *  Creates a new instance of Planet
     *
     * @param input_radius How large the planet is in space
     * @param input_x The new Planet's starting x-coordinate
     * @param input_y The new Planet's starting y-coordinate
     * @param input_orbit_radius The size of the new Planet's orbital radius
     */
    public Planet(int input_radius, int input_x, int input_y, int input_orbit_radius)
    {
        super(input_radius, input_x, input_y);

        orbit_radius = input_orbit_radius;
        moons_orbiting_planet = 0;
        t = 0;
    }


    /**
     * Updates the position of the Planet within space. The planet will go in a continuous circle.
     */
    public void update()
    {

        for (int i = 0; i < 3; i++) //The for loop is used to ensure that the Planet's movement
        {                           //in space is represented properly
            //The equations used for the Planet's velocity are parametric
            setX((int) Math.round(getX() + (-1) * orbit_radius * sin(Math.toRadians(t))));
            setY((int) Math.round(getY() + (-1) * orbit_radius * cos(Math.toRadians(t))));

            t += 1;
        }

    }

    /**
     * Increments the object's counter which keeps track of how many Moons are associated with the Planet
     */
    public void addToMoonCount()
    {
        moons_orbiting_planet += 1;
    }

    /**
     * Returns the amount of Moons that are associated with the current Planet
     *
     * @return the amount of Moons that are associated with the current Planet
     */
    public int getMoonCount()
    {
        return moons_orbiting_planet;
    }

}
