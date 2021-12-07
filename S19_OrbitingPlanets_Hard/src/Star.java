/**
 *  A subclass of CelestialObject, a Star is simply a circular object in 2D space which remains still.
 *
 * @author Austin Piper <austin-piper@uiowa.edu></austin-piper@uiowa.edu>
 * @version 1.0
 * @since 4/2/2021
 */
public class Star extends CelestialObject
{
    /**
     * Creates an instance of 'Star'
     *
     * @param input_radius The radius that the new Star will have in 2D space
     * @param input_x The new Star's beginning x-coordinate
     * @param input_y The new Star's beginning y-coordinate
     */
    public Star(int input_radius, int input_x, int input_y)
    {
        super(input_radius, input_x, input_y);
    }

    /**
     * The update method for 'Star' has an empty implementation. This is because it is meant to stand still, and
     * (typically) not change.
     */
    @Override
    public void update()
    {}
}
