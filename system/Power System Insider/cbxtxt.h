#pragma once

#include <string>

std::string commandlist[100] =
{
	"ver",//
	"out",//
	"print",//
	"echo",//
	"clear",//
	"cls",//
	"exit",//
	"none",//
	"rainbow",//
	"quit",//10
	"error",//
	"help",//
	"graph",//
	"reboot",//14
	"errscreen",//
	"getruntime",//
	"nextskipboot",//
	"pause",//
	"fullram",//19
	"clearram",//
	"fulledram",//
	"track",//
	"file",//
	"launch",//
	"loadaudio",//
	"setroot",//
	"stopmedia",//
	"setusername",//28
	"setuser",//
	"setusertrm",//
	"mkfile",//
	"writefile",//
	"isfileexist",//
	"dir",//
	"readfile",//
	"delete",//
	"mkdir",//
	"rmdir",//
	"cmdmode",//
	"asset mode",//40
	"fullfile",//
	"copy",//
	"move",//
	"rename",//
	"ren",//
	"fc",//removed:(
	"debug",//
	"init debugpack",//
	"cd..",//
	"cd",//
	"hash",//51
	"shash",//
	"loadimage",//
	"",//
	"reloadtype",//55
	"saveimage",//
	"setgraphsize",//
	"setparent",//
	"",//
	"setpin",//60
	"setthisusername",//61
	"base64encode",//
	"base64decode",//
	"guitrack",//
	"sleep",//65
	"downloadfile"//
};
std::string helps[100]
{
	"Display Version information",
	"Print sentence",
	"Print sentence",
	"Print sentence",
	"Clear screen",
	"Clear screen",
	"Exit PSE System",
	"None",
	"Display a raindow on screen",
	"Exit PSE System",
	"Crash",
	"Display All command",
	"Init graphics(DEMO)",
	"Reboot the machine",
	"Happy",
	"Get system run time",
	"Next boot will fast boot",
	"Pause system",
	"Full RAM",
	"Removed",
	"Removed",
	"Loading track",
	"Removed",
	"Launch a app",
	"Load a audio",
	"Set file control directory",
	"Stop the media",
	"Removed",
	"Removed",
	"Removed",
	"Make empty file",
	"Write file(On end)",
	"Scan is file exist",
	"Show directory all files and directorys",
	"Read file",
	"Delete file",
	"Make directory",
	"Remove directory",
	"Launch CMD.exe",
	"Removed",
	"Full a file",
	"Copy file",
	"Muve File",
	"Rename file",
	"Rename File",
	"Compare two file",
	"Show the point of the variables",
	"Init the DebugPack",
	"Set control root up directory",
	"Set root",
	"Compute file hash",
	"Compute string hash",
	"Load a picture.",
	"Removed",
	"Reload the type system",
	"Save image to a file with the text.",
	"Set Graphics size",
	"Set Window Parent(debug)",
	"Removed",
	"Set User PIN",
	"Set User name",
	"Decode Base64",
	"Encode Base64",
	"GUI version track",
	"Sleep",
	"Download file from URL",
};

std::string ver =
"\
==========       =====       ==        ===      ==    ===========    ========\n\
|         \\    --     --      ==      ====     ==     |             |        \\\n\
|          |  -         -     ==      ====     ==     |             |         |\n\
|         /  -           -     ==    ==  ==   ==      |             |        /\n\
|=========   -           -     ==    ==  ==   ==      |========     |======= \n\
|            -           -      ==  ==    == ==       |             | \\\n\
|             -         -       ==  ==    == ==       |             |  \\\n\
|              --     --         ====      ====       |             |   \\\n\
|                =====            ===      ===        ===========   |    \\\n\
System  2.6.3     \n\
Bilibili/pack-12900                                                    PSE Studios\n\
Psertded\n\n";