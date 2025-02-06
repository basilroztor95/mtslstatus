/*
 * for components info see: wiki/COMPONENTS.md
 *
 * extra configs in can be found in `components_config.h`
 */

/* for usleep */
#define _SEC *1000
#define _MIN *(60 _SEC)
#define _HR  *(60 _MIN)

/* interval to run only once */
#define ONCE ((unsigned int)-1)

/* text to show if no value can be retrieved */
static const char unknown_str[] = "n/a";

/* maximum output string length */
#define MAXLEN 256
/*
 * if you want to change buffer size for each segment,
 * then change `BUFF_SZ` in lib/util.h
 */

#define IFC "wlan0" /* wifi interface */

/* clang-format off */
static struct arg_t args[] = {

/* function		format		argument	interval (in ms) */

#if USE_X
/* { bspwm_ws,		" [ %s ]%%{r}",	NULL,		0,	END }, */
#endif
// interval 0 is completely broken!
//{ run_command,	            "%s",	"~/.scripts/volume.sh",       0,    	 END },

{ run_command,		    " %s ",	"~/.scripts/internet.sh",     5 _SEC,	 END },
{ run_command,		    "| %s ",	"~/.scripts/usd.sh",          1 _HR,	 END },
{ cpu_perc,		    "| %s ",	NULL,		              1 _SEC,	 END },
{ netspeed_rx,	            "| %s ",	"enp5s0",	              1 _SEC,    END },
{ netspeed_tx,	            "%s ",	"enp5s0",	              1 _SEC,    END },
{ datetime,	            "| %s",	"%T",                         1 _SEC,    END },

//#if USE_X && USE_XKB
//{ keymap,		"-[ %s] ",	NULL,		 0,	END },
//#endif

};
/* clang-format on */
