import java.awt.Color;
import javax.swing.JFrame;

public class Window extends JFrame{
    Window(){ //create a frame
        this.setTitle("GUI TEST");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //frame.setResizable(false);
        this.setSize(800,800);
        this.setVisible(true);//making it visible
        
        //Setting Image Icon to the window
        //ImageIcon image = new ImageIcon("../NOTES/Resources/icon.png");
        //frame.setIconImage(image.getImage());

        this.getContentPane().setBackground(new Color(131,139,167));
    }
}
