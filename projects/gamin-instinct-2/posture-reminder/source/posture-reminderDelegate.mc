import Toybox.Lang;
import Toybox.WatchUi;

class posture_reminderDelegate extends WatchUi.BehaviorDelegate {

    function initialize() {
        BehaviorDelegate.initialize();
    }

    function onMenu() as Boolean {
        WatchUi.pushView(new Rez.Menus.MainMenu(), new posture_reminderMenuDelegate(), WatchUi.SLIDE_UP);
        return true;
    }

}