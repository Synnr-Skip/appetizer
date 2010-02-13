package {
	
	/**
	 * The functions and objects of this special class are accessible from anywhere in Lua. They
	 * are usually an access point to the application objects or to certain utility functions.
	 */
	public class Global {
		
	/**
	 * The application object
	 */		
		public var appetizer:Application;
		
	/**
	 * The option panel where the option buttons are displayed
	 */			
		public var optionPanel:OptionPanel;
		
		
	/**
	 * The dialogs object that can be used to show different kind of dialog boxes
	 */				
		public var dialogs:Dialogs;
		
		
	/**
	 * The system object may be used to access various system functions
	 */		
		public var system:System;
		
		
	/**
	 * The current plugin object. May be used to access functions and properties related to the plugin itself
	 */		
		public var plugin:Plugin;
		
	
	/**
	 * The preference registry. Can be used to get or set preference values
	 */		
		public var preferences:Preferences;
		
		
	/**
	 * Debug function used to display a message in the debug window. Any number of
	 * parameters can be specified.
	 * @example The following code displays some debugging messages in the log window:
	 * <listing version="3.0">
	 * trace("The app visibility is ", appetizer:isVisible(), " and its orientation is ", appetizer:getOrientation())
	 * trace("Is the option panel open? ", optionPanel:isOpen()) 
	 * </listing>
	 */		
		public function trace(s1:String = "", s2:String = "", etc:String = ""):void {}
		
	/**
	 * Makes the wrapped string localizable. See Securizer plugin for an example.
	 * @param String string The string to tag for localization
	 * @return String The localized string
	 */		
		public function _(string:String):String { return ""; }
		
	}	
	
}