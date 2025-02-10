import Toybox.Application;
import Toybox.WatchUi;
import Toybox.Background;
import Toybox.System;
import Toybox.Attention;
import Toybox.Time;

(:background)
class PostureReminderApp extends Application.AppBase {
    private const REMINDER_INTERVAL = new Time.Duration(1800); // 30 minutes

    function initialize() {
        AppBase.initialize();
    }

    function onStart(state) {
        var nextTime = Time.now().add(REMINDER_INTERVAL);
        Background.registerForTemporalEvent(nextTime);
    }

    function onStop(state) {
        Background.deleteTemporalEvent();
    }

    function getInitialView() {
        return [ new PostureReminderView() ];
    }

    function onBackgroundData(data) {
        // Show notification
        Attention.vibrate([new Attention.VibeProfile(50, 2000)]);
        WatchUi.showToast("Check Your Posture\nRemember to sit up straight!", {});
        
        // Register for next reminder
        var nextTime = Time.now().add(REMINDER_INTERVAL);
        Background.registerForTemporalEvent(nextTime);
    }
}