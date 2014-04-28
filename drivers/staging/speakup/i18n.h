#ifndef I18N_H
#define I18N_H

enum msg_index_t {
	MSG_FIRST_INDEX ,
	MSG_ANNOUNCEMENTS_START = MSG_FIRST_INDEX,
	MSG_BLANK = MSG_ANNOUNCEMENTS_START,
	MSG_IAM_ALIVE,
	MSG_YOU_KILLED_SPEAKUP,
	MSG_HEY_THATS_BETTER,
	MSG_YOU_TURNED_ME_OFF,
	MSG_PARKED,
	MSG_UNPARKED,
	MSG_MARK,
	MSG_CUT,
	MSG_MARK_CLEARED,
	MSG_PASTE,
	MSG_BRIGHT,
	MSG_ON_BLINKING,
	MSG_STATUS_START,
	MSG_OFF = MSG_STATUS_START,
	MSG_ON,
	MSG_NO_WINDOW,
	MSG_CURSOR_MSGS_START,
	MSG_CURSORING_OFF = MSG_CURSOR_MSGS_START,
	MSG_CURSORING_ON,
	MSG_HIGHLIGHT_TRACKING,
	MSG_READ_WINDOW,
	MSG_READ_ALL,
	MSG_EDIT_DONE,
	MSG_WINDOW_ALREADY_SET,
	MSG_END_BEFORE_START,
	MSG_WINDOW_CLEARED,
	MSG_WINDOW_SILENCED,
	MSG_WINDOW_SILENCE_DISABLED,
	MSG_ERROR,
	MSG_GOTO_CANCELED,
	MSG_GOTO,
	MSG_LEAVING_HELP,
	MSG_IS_UNASSIGNED,
	MSG_HELP_INFO,
	MSG_EDGE_MSGS_START,
	MSG_EDGE_TOP  = MSG_EDGE_MSGS_START,
	MSG_EDGE_BOTTOM,
	MSG_EDGE_LEFT,
	MSG_EDGE_RIGHT,
	MSG_NUMBER,
	MSG_SPACE,
	MSG_START, 
	MSG_END, 
	MSG_CTRL,

	MSG_DISJUNCTION,
	MSG_ANNOUNCEMENTS_END = MSG_DISJUNCTION,

	MSG_FORMATTED_START,
	MSG_POS_INFO = MSG_FORMATTED_START,
	MSG_CHAR_INFO,
	MSG_REPEAT_DESC,
	MSG_REPEAT_DESC2,
	MSG_WINDOW_LINE,
	MSG_WINDOW_BOUNDARY,
	MSG_EDIT_PROMPT,
	MSG_NO_COMMAND,
	MSG_KEYDESC,
	MSG_FORMATTED_END = MSG_KEYDESC,

	
	MSG_CTL_START,
	MSG_CTL_SHIFT = MSG_CTL_START,
	MSG_CTL_ALTGR,
	MSG_CTL_CONTROL,
	MSG_CTL_ALT,
	MSG_CTL_LSHIFT,
	MSG_CTL_SPEAKUP,
	MSG_CTL_LCONTROL,
	MSG_CTL_RCONTROL,
	MSG_CTL_CAPSSHIFT,
	MSG_CTL_END = MSG_CTL_CAPSSHIFT,

	
	MSG_COLORS_START,
	MSG_COLOR_BLACK = MSG_COLORS_START,
	MSG_COLOR_BLUE,
	MSG_COLOR_GREEN,
	MSG_COLOR_CYAN,
	MSG_COLOR_RED,
	MSG_COLOR_MAGENTA,
	MSG_COLOR_YELLOW,
	MSG_COLOR_WHITE,
	MSG_COLOR_GREY,
	MSG_COLORS_END = MSG_COLOR_GREY,

	MSG_STATES_START,
	MSG_STATE_DOUBLE = MSG_STATES_START,
	MSG_STATE_SPEAKUP,
	MSG_STATE_ALT,
	MSG_STATE_CONTROL,
	MSG_STATE_ALTGR,
	MSG_STATE_SHIFT,
	MSG_STATES_END = MSG_STATE_SHIFT,

	MSG_KEYNAMES_START,
	MSG_KEYNAME_ESC = MSG_KEYNAMES_START,
	MSG_KEYNAME_1, MSG_KEYNAME_2, MSG_KEYNAME_3, MSG_KEYNAME_4,
	MSG_KEYNAME_5, MSG_KEYNAME_6, MSG_KEYNAME_7, MSG_KEYNAME_8, MSG_KEYNAME_9,
	MSG_KEYNAME_0, MSG_KEYNAME_DASH, MSG_KEYNAME_EQUAL, MSG_KEYNAME_BS,
	MSG_KEYNAME_TAB,
	MSG_KEYNAME_Q, MSG_KEYNAME_W, MSG_KEYNAME_E, MSG_KEYNAME_R, MSG_KEYNAME_T,
	MSG_KEYNAME_Y, MSG_KEYNAME_U, MSG_KEYNAME_I, MSG_KEYNAME_O, MSG_KEYNAME_P,
	MSG_KEYNAME_LEFTBRACE, MSG_KEYNAME_RIGHTBRACE, MSG_KEYNAME_ENTER,
	MSG_KEYNAME_LEFTCTRL, MSG_KEYNAME_A,
	MSG_KEYNAME_S, MSG_KEYNAME_D, MSG_KEYNAME_F, MSG_KEYNAME_G, MSG_KEYNAME_H,
	MSG_KEYNAME_J, MSG_KEYNAME_K, MSG_KEYNAME_L, MSG_KEYNAME_SEMICOLON,
	MSG_KEYNAME_SINGLEQUOTE, MSG_KEYNAME_GRAVE,
	MSG_KEYNAME_LEFTSHFT, MSG_KEYNAME_BACKSLASH, MSG_KEYNAME_Z, MSG_KEYNAME_X,
	MSG_KEYNAME_C, MSG_KEYNAME_V, MSG_KEYNAME_B, MSG_KEYNAME_N, MSG_KEYNAME_M,
	MSG_KEYNAME_COMMA, MSG_KEYNAME_DOT, MSG_KEYNAME_SLASH, MSG_KEYNAME_RIGHTSHFT,
	MSG_KEYNAME_KPSTAR,
	MSG_KEYNAME_LEFTALT, MSG_KEYNAME_SPACE, MSG_KEYNAME_CAPSLOCK,
	MSG_KEYNAME_F1, MSG_KEYNAME_F2,
	MSG_KEYNAME_F3, MSG_KEYNAME_F4, MSG_KEYNAME_F5, MSG_KEYNAME_F6,
	MSG_KEYNAME_F7,
	MSG_KEYNAME_F8, MSG_KEYNAME_F9, MSG_KEYNAME_F10, MSG_KEYNAME_NUMLOCK,
	MSG_KEYNAME_SCROLLLOCK,
	MSG_KEYNAME_KP7, MSG_KEYNAME_KP8, MSG_KEYNAME_KP9, MSG_KEYNAME_KPMINUS,
	MSG_KEYNAME_KP4,
	MSG_KEYNAME_KP5, MSG_KEYNAME_KP6, MSG_KEYNAME_KPPLUS, MSG_KEYNAME_KP1,
	MSG_KEYNAME_KP2,
	MSG_KEYNAME_KP3, MSG_KEYNAME_KP0, MSG_KEYNAME_KPDOT, MSG_KEYNAME_103RD,
	MSG_KEYNAME_F13,
	MSG_KEYNAME_102ND, MSG_KEYNAME_F11, MSG_KEYNAME_F12, MSG_KEYNAME_F14,
	MSG_KEYNAME_F15,
	MSG_KEYNAME_F16, MSG_KEYNAME_F17, MSG_KEYNAME_F18, MSG_KEYNAME_F19,
	MSG_KEYNAME_F20,
	MSG_KEYNAME_KPENTER, MSG_KEYNAME_RIGHTCTRL, MSG_KEYNAME_KPSLASH,
	MSG_KEYNAME_SYSRQ, MSG_KEYNAME_RIGHTALT,
	MSG_KEYNAME_LF, MSG_KEYNAME_HOME, MSG_KEYNAME_UP, MSG_KEYNAME_PGUP,
	MSG_KEYNAME_LEFT,
	MSG_KEYNAME_RIGHT, MSG_KEYNAME_END, MSG_KEYNAME_DOWN, MSG_KEYNAME_PGDN,
	MSG_KEYNAME_INS,
	MSG_KEYNAME_DEL, MSG_KEYNAME_MACRO, MSG_KEYNAME_MUTE,
	MSG_KEYNAME_VOLDOWN, MSG_KEYNAME_VOLUP,
	MSG_KEYNAME_POWER, MSG_KEYNAME_KPEQUAL, MSG_KEYNAME_KPPLUSDASH, MSG_KEYNAME_PAUSE, MSG_KEYNAME_F21,
	MSG_KEYNAME_F22, MSG_KEYNAME_F23, MSG_KEYNAME_F24, MSG_KEYNAME_KPCOMMA, MSG_KEYNAME_LEFTMETA,
	MSG_KEYNAME_RIGHTMETA, MSG_KEYNAME_COMPOSE, MSG_KEYNAME_STOP,
	MSG_KEYNAME_AGAIN, MSG_KEYNAME_PROPS,
	MSG_KEYNAME_UNDO, MSG_KEYNAME_FRONT, MSG_KEYNAME_COPY, MSG_KEYNAME_OPEN,
	MSG_KEYNAME_PASTE,
	MSG_KEYNAME_FIND, MSG_KEYNAME_CUT, MSG_KEYNAME_HELP, MSG_KEYNAME_MENU,
	MSG_KEYNAME_CALC,
	MSG_KEYNAME_SETUP, MSG_KEYNAME_SLEEP, MSG_KEYNAME_WAKEUP,
	MSG_KEYNAME_FILE, MSG_KEYNAME_SENDFILE,
	MSG_KEYNAME_DELFILE, MSG_KEYNAME_XFER, MSG_KEYNAME_PROG1,
	MSG_KEYNAME_PROG2, MSG_KEYNAME_WWW,
	MSG_KEYNAME_MSDOS, MSG_KEYNAME_COFFEE, MSG_KEYNAME_DIRECTION,
	MSG_KEYNAME_CYCLEWINDOWS, MSG_KEYNAME_MAIL,
	MSG_KEYNAME_BOOKMARKS, MSG_KEYNAME_COMPUTER, MSG_KEYNAME_BACK,
	MSG_KEYNAME_FORWARD, MSG_KEYNAME_CLOSECD,
	MSG_KEYNAME_EJECTCD, MSG_KEYNAME_EJECTCLOSE, MSG_KEYNAME_NEXTSONG,
	MSG_KEYNAME_PLAYPAUSE, MSG_KEYNAME_PREVSONG,
	MSG_KEYNAME_STOPCD, MSG_KEYNAME_RECORD, MSG_KEYNAME_REWIND,
	MSG_KEYNAME_PHONE, MSG_KEYNAME_ISO,
	MSG_KEYNAME_CONFIG, MSG_KEYNAME_HOMEPG, MSG_KEYNAME_REFRESH,
	MSG_KEYNAME_EXIT, MSG_KEYNAME_MOVE,
	MSG_KEYNAME_EDIT, MSG_KEYNAME_SCROLLUP, MSG_KEYNAME_SCROLLDN,
	MSG_KEYNAME_KPLEFTPAR, MSG_KEYNAME_KPRIGHTPAR,
	MSG_KEYNAMES_END = MSG_KEYNAME_KPRIGHTPAR,

	MSG_FUNCNAMES_START,
	MSG_FUNCNAME_ATTRIB_BLEEP_DEC = MSG_FUNCNAMES_START,
	MSG_FUNCNAME_ATTRIB_BLEEP_INC,
	MSG_FUNCNAME_BLEEPS_DEC, MSG_FUNCNAME_BLEEPS_INC,
	MSG_FUNCNAME_CHAR_FIRST, MSG_FUNCNAME_CHAR_LAST,
	MSG_FUNCNAME_CHAR_CURRENT, MSG_FUNCNAME_CHAR_HEX_AND_DEC,
	MSG_FUNCNAME_CHAR_NEXT,
	MSG_FUNCNAME_CHAR_PHONETIC, MSG_FUNCNAME_CHAR_PREVIOUS,
	MSG_FUNCNAME_CURSOR_PARK, MSG_FUNCNAME_CUT,
	MSG_FUNCNAME_EDIT_DELIM, MSG_FUNCNAME_EDIT_EXNUM,
	MSG_FUNCNAME_EDIT_MOST, MSG_FUNCNAME_EDIT_REPEATS, MSG_FUNCNAME_EDIT_SOME,
	MSG_FUNCNAME_GOTO, MSG_FUNCNAME_GOTO_BOTTOM, MSG_FUNCNAME_GOTO_LEFT,
	MSG_FUNCNAME_GOTO_RIGHT, MSG_FUNCNAME_GOTO_TOP, MSG_FUNCNAME_HELP,
	MSG_FUNCNAME_LINE_SAY_CURRENT, MSG_FUNCNAME_LINE_SAY_NEXT,
	MSG_FUNCNAME_LINE_SAY_PREVIOUS, MSG_FUNCNAME_LINE_SAY_WITH_INDENT,
	MSG_FUNCNAME_PASTE, MSG_FUNCNAME_PITCH_DEC, MSG_FUNCNAME_PITCH_INC,
	MSG_FUNCNAME_PUNC_DEC, MSG_FUNCNAME_PUNC_INC,
	MSG_FUNCNAME_PUNC_LEVEL_DEC, MSG_FUNCNAME_PUNC_LEVEL_INC,
	MSG_FUNCNAME_QUIET,
	MSG_FUNCNAME_RATE_DEC, MSG_FUNCNAME_RATE_INC,
	MSG_FUNCNAME_READING_PUNC_DEC, MSG_FUNCNAME_READING_PUNC_INC,
	MSG_FUNCNAME_SAY_ATTRIBUTES,
	MSG_FUNCNAME_SAY_FROM_LEFT, MSG_FUNCNAME_SAY_FROM_TOP,
	MSG_FUNCNAME_SAY_POSITION, MSG_FUNCNAME_SAY_SCREEN,
	MSG_FUNCNAME_SAY_TO_BOTTOM, MSG_FUNCNAME_SAY_TO_RIGHT,
	MSG_FUNCNAME_SPEAKUP, MSG_FUNCNAME_SPEAKUP_LOCK,
	MSG_FUNCNAME_SPEAKUP_OFF, MSG_FUNCNAME_SPEECH_KILL,
	MSG_FUNCNAME_SPELL_DELAY_DEC, MSG_FUNCNAME_SPELL_DELAY_INC,
	MSG_FUNCNAME_SPELL_WORD, MSG_FUNCNAME_SPELL_WORD_PHONETICALLY,
	MSG_FUNCNAME_TONE_DEC, MSG_FUNCNAME_TONE_INC,
	MSG_FUNCNAME_VOICE_DEC, MSG_FUNCNAME_VOICE_INC,
	MSG_FUNCNAME_VOLUME_DEC, MSG_FUNCNAME_VOLUME_INC,
	MSG_FUNCNAME_WINDOW_CLEAR, MSG_FUNCNAME_WINDOW_SAY,
	MSG_FUNCNAME_WINDOW_SET, MSG_FUNCNAME_WINDOW_SILENCE,
	MSG_FUNCNAME_WORD_SAY_CURRENT, MSG_FUNCNAME_WORD_SAY_NEXT,
	MSG_FUNCNAME_WORD_SAY_PREVIOUS,
	MSG_FUNCNAMES_END = MSG_FUNCNAME_WORD_SAY_PREVIOUS,

	
	MSG_LAST_INDEX
};

struct msg_group_t {
	char *name;
	enum msg_index_t start;
	enum msg_index_t end;
};

extern char *msg_get(enum msg_index_t index);
extern ssize_t msg_set(enum msg_index_t index, char *text, size_t length);
extern struct msg_group_t *find_msg_group(const char *group_name);
extern void reset_msg_group(struct msg_group_t *group);
extern void initialize_msgs(void);
extern void free_user_msgs(void);

#endif
