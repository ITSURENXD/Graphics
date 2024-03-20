import javax.swing.ImageIcon;
import javax.swing.JLabel;

public class Main {
    public static void main(String[] args){
        ImageIcon image = new ImageIcon("../NOTES/Resources/icon.png");
        JLabel label = new JLabel(); //create Label
        //JLabel label = new JLabel("Hello World"); //shorter way to do instead of setText
        label.setText("Hello World"); //Set Text of Label
        label.setIcon(image); // setting icon to Label
        Window window = new Window();
        window.add(label);
    }
}
