import static java.lang.Math.*;

/**
 *  A Moon object is one that orbits around a host Planet in 2D space. Like a Planet, a Moon also has a changing velocity.
 *  Each Planet can only have up to 2 Moons associated with it, assuming a standard implementation of KeyboardPressHandler
 *  in SolarSystemPanel
 *
 * @author Austin Piper <austin-piper@uiowa.edu></austin-piper@uiowa.edu>
 * @version 1.0
 * @since 3/28/2021
 */
public class Moon extends CelestialObject
{
    /**
     * A reference to the Planet which the current Moon orbits around
     */
    private Planet hostPlanet;

    /**
     * The radius of orbit which the Moon has around its Host Planet
     */
    private int orbital_radius;

    /**
     * The Moon's velocity is determined using a set of parametric equations. This is the parametric variable.
     *
     * @see update
     */
    private int t;

    /**
     *
     * @param input_hostPlanet A reference to the Planet which will be the Moon's host
     * @param input_radius The physical size of the new Moon within 2D space
     * @param input_orbital_radius The radius of orbit which the new Moon has around its host Planet
     */
    public Moon(Planet input_hostPlanet, int input_radius, int input_orbital_radius)
    {


        super(input_radius, 0 , 0 );   //The moon's position within space is initially set to zero
                                                     //and then changed later in the constructor so that
        hostPlanet = input_hostPlanet;               //only one call has to be made to the host planet's
        orbital_radius = input_orbital_radius;       //getCoordinates() method
        t = 0;

        int host_planet_coordinates[] = hostPlanet.getCoordinates();

        setX((int) Math.round(host_planet_coordinates[0] + getRadius() + input_orbital_radius * (sqrt(2)/2)));
        setY((int) Math.round(host_planet_coordinates[1] + input_orbital_radius * (sqrt(2)/2)));
    }

    /**
     * Updates the Moon's position within 2D space. It first sets the Moon itself
     * relative to the host Planet, then adjust this position to reflect the
     * Moon's position within its orbit.
     */
    @Override
    public void update()
    {
        int host_planet_coordinates[] = hostPlanet.getCoordinates();

        for (int i = 0; i < 15; i++) //This for loop is used to ensure that the Moon's movement
        {                            //in space is accurately represented
            //Set moon's position relative to its hostPlanet
            setX((int) host_planet_coordinates[0] + hostPlanet.getRadius()); //Sets the Moon relative to its host Planet
            setY((int) host_planet_coordinates[1] + hostPlanet.getRadius()/2);

            //The equations used for the moon's velocity relative to its host planet are parametric
            setX((int) (getX() + (-1) * orbital_radius * sin(Math.toRadians(t))));//Now the Moon's position relative to its
            setY((int) (getY() + (-1) * orbital_radius * cos(Math.toRadians(t))));//position in orbit is set
            t += 1;
        }

    }
}
