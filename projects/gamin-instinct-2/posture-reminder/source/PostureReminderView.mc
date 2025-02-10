import Toybox.WatchUi;
import Toybox.Graphics;

class PostureReminderView extends WatchUi.View {
    function initialize() {
        View.initialize();
    }

    function onUpdate(dc) {
        dc.setColor(Graphics.COLOR_BLACK, Graphics.COLOR_WHITE);
        dc.clear();
        dc.setColor(Graphics.COLOR_BLACK, Graphics.COLOR_TRANSPARENT);
        
        var centerX = dc.getWidth() / 2;
        var centerY = dc.getHeight() / 2;
        
        dc.drawText(
            centerX,
            centerY,
            Graphics.FONT_MEDIUM,
            "Posture Reminder Active",
            Graphics.TEXT_JUSTIFY_CENTER
        );
    }
} 