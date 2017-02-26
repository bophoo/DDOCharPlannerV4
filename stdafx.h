#ifndef stdafxh
#define stdafxh

#include <windows.h>
#include <stdio.h>
#include <richedit.h>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <strsafe.h>
#include <Richole.h>
#include <iostream>
#include <unordered_map>

using namespace std;

#define VERSION "4.34.201"
#define NUMCLASSES 14
#define NUMRACES 14
#define MAXLEVEL 30
#define HEROICLEVELS 20
#define NUMSKILLS 21
#define NUMSPELLLEVELS 9
#define NUMCHAREQUPMENTSLOTS 16
#define NONE 100000
#define NUMDATAFILES 11
#define nullptr 0
#define DEFAULTWIDTH 1024
#define DEFAULTHEIGHT 768
#define NUM_ENHANCEMENT_TREES 61
#define NUM_DESTINY_TREES 13
#define PASTLIFEFEAT 14
#define EPICPASTLIFESPHERE 4
#define ICONICPASTLIFEFEAT 5

enum WINDOWID {MS_NAMELABEL, MS_RACECLASSLABEL,
               MS_LOADBUTTON, MS_SAVEBUTTON, MS_CLEARBUTTON, MS_PRINTBUTTON, MS_FORUMEXPORTBUTTON, MS_ABOUTBUTTON, MS_QUITBUTTON, MS_EQUIPMENTSCREENBUTTON, MS_ITEMBUILDERBUTTON, MS_DISPLAYERRORBUTTON,
			   MS_DESTINYPANELBUTTON, MS_FEATSPANELBUTTON, MS_SPELLSPANELBUTTON,MS_ENHPANELBUTTON,
               MS_DESCRIPTIONWINDOW, MS_ADVANCEMENTWINDOWFRAME, MS_INSTRUCTIONWINDOWFRAME,
               MS_STRLABEL, MS_DEXLABEL, MS_CONLABEL, MS_INTLABEL, MS_WISLABEL, MS_CHALABEL,
               MS_STRLABEL2, MS_DEXLABEL2, MS_CONLABEL2, MS_INTLABEL2, MS_WISLABEL2, MS_CHALABEL2,
               MS_ABILITYBOXFRAME, MS_ABILITYLABEL, MS_ABILITYMODIFIERLABEL,
               MS_STRNUMBER, MS_DEXNUMBER, MS_CONNUMBER, MS_INTNUMBER, MS_WISNUMBER, MS_CHANUMBER,
               MS_STRMODIFIER, MS_DEXMODIFIER, MS_CONMODIFIER, MS_INTMODIFIER, MS_WISMODIFIER, MS_CHAMODIFIER,
               MS_ABILITYSTATBOXFRAME, MS_ABILITYSTATBOX,
               MS_SPELLBOXFRAME, MS_SPELLBOXLABEL, MS_SPELLLIST,MS_DESTINYBOXFRAME, MS_DESTINYBOXLABEL,MS_DESTINYLIST,
               MS_SKILLBOXFRAME, MS_SKILLTITLE, MS_KEYABILITYTITLE, MS_TOTALMODTITLE, MS_ABILITYMODTITLE, MS_MISCMODTITLE, MS_SKILLSLIST,
			   MS_FEATBOXFRAME, MS_FEATLISTLABEL, MS_FEATSLIST, MS_IW_TITLE, MS_IW_LIST, 
			   MS_SIDEMENUTITLE, MS_SIDERACESEX, MS_SIDECLASS, MS_SIDEREINCARNATION, MS_SIDEABILITY, MS_SIDESKILL, MS_SIDESPELL, 
			   MS_SIDEFEATS, MS_SIDEDESTINY, MS_SIDEENHANCEMENTS,MS_NAMEANDALIGNMENTBUTTON,
			   MS_ENHANCEMENTBOXFRAME, MS_ENHANCEMENTLABEL, MS_ENHANCEMENTLIST,
               MS_ADVWINBONUSABILITY, MS_ADVWINFEATSLIST, MS_ADVWINFIRSTNAMEINPUT, MS_ADVWINSURNAMEINPUT, MS_ADVWINSKILLSPEND, MS_ADVWINSPELLLIST, MS_ES_ADVWINSPELLCLEARBUTTON,
               MS_ES_TITLE, MS_ED_TITLE, MS_EQUIPMENTSELECTLIST,MS_HERIOCPASTLIFE,MS_ICONICPASTLIFE,MS_EPICPASTLIFE,
               MS_EQUIPMENTDISPLAYSELECTLIST, MS_AS_TITLE, MS_ASLIST, MS_HEROICLEVELRADIO, MS_EPICLEVELRADIO, MS_HEROICCLASS, MS_ICONICCLASS,
               LW_LOADRACELABEL, LW_LOADCLASSLABEL, LW_LOADFEATLABEL, LW_LOADSKILLLABEL, LW_LOADENHANCEMENTLABEL, LW_LOADSPELLLABEL, LW_LOADEQUIPMENTLABEL, LW_LOADITEMEFFECTLABEL, LW_LOADITEMCLICKYEFFECTLABEL, LW_LOADITEMLABEL, LW_LOADTEMPLATELABEL, LW_LOADDESTINYLABEL,
               AB_ABOUTBOX, AB_CLOSEBUTTON,
			   PW_PRINTLABEL, PW_PRINTBUTTON, PW_CANCELBUTTON, PW_PRINTSNAPSHOTCHECKBOX, PW_SNAPSHOTLEVELSELECTLABEL, PW_PRINTLEVELGUIDECHECKBOX, PW_LEVELGUILDLEVELSELECTLOWLABEL, PW_LEVELGUILDLEVELSELECTHIGHLABEL, PW_PRINTSNAPSHOTMAXLEVELRADIOBUTTON, PW_PRINTSNAPSHOTOTHERLEVELRADIOBUTTON, PW_PRINTSNAPSHOTOTHERLEVELINPUTBOX,
			   PW_PRINTLEVELGUIDEDEFAULTLEVELSRADIOBUTTON, PW_PRINTLEVELGUIDEOTHERLEVELSRADIOBUTTON, PW_PRINTLEVELGUIDEOTHERLEVELLOWINPUTBOX, PW_PRINTLEVELGUIDEOTHERLEVELHIGHINPUTBOX,
               FE_LEVELSELECTLABEL, FE_LEVELSELECT, FE_CLOSEBUTTON, FE_COPYBUTTON, FE_PRESETSLABEL, FE_PRESET1, FE_PRESET2, FE_EXAMPLEOUTPUTBOX, FE_HEADERLABEL, FE_NAMECHECKBOX,
               FE_ABILITYLABEL, FE_STARTINGABILITYCHECKBOX, FE_ENDINGABILITYCHECKBOX, FE_MODIFIEDABILITYCHECKBOX,
               FE_SKILLSLABEL, FE_STARTINGSKILLSCHECKBOX, FE_ENDINGSKILLSCHECKBOX, FE_MODIFIEDSKILLSCHECKBOX, FE_FINALENHANCEMENTSCHECKBOX, FE_NOTABLEEQUIPMENTCHECKBOX,
			   FE_LEVELBREAKDOWNLABEL, FE_ABILITYRAISECHECKBOX, FE_SKILLSLISTCHECKBOX, FE_FEATSELECTEDCHECKBOX, FE_FEATAUTOCHECKBOX, FE_SPELLSCHECKBOX, FE_ENHANCEMENTSCHECKBOX,
			   FE_FORUMBACKGROUNDLABEL, FE_FORUMBACKGROUNDDARKRADIOBUTTON, FE_FORUMBACKGROUNDLIGHTRADIOBUTTON, FE_TEMPLATESELECTLABEL, FE_TEMPLATESELECT, FE_TEMPLATEDESIGNBUTTON, 
				IB_CLOSEBUTTON, IB_ADDBUTTON, IB_REMOVEBUTTON, IB_TITLELABEL,
				IB_SLOTTYPEFRAME, IB_SLOTTYPELABEL, 
				IB_BUILDTYPEFRAME, IB_BUILDTYPELABEL,IB_GISELECTBOX, IB_NISELECTBOX, IB_GSSELECTBOX, IB_DTSELECTBOX, IB_SRSELECTBOX, IB_EPICSELECTBOX, 
				IB_BASETYPEFRAME, IB_BASETYPELABEL,IB_BASETYPELIST, 
				IB_CURRENTITEMSFRAME, IB_CURRENTITEMSLABEL, IB_CURRENTITEMSLIST,
				IB_BONUSEFFECTFRAME, IB_BONUSEFFECTLABEL, IB_BONUSEFFECTLIST,
				IB_PREFIXEFFECTFRAME, IB_PREFIXEFFECTLABEL, IB_PREFIXEFFECTLIST,
				IB_MATERIALEFFECTFRAME, IB_MATERIALEFFECTLABEL, IB_MATERIALEFFECTLIST,
				IB_SUFFIXEFFECTFRAME, IB_SUFFIXEFFECTLABEL, IB_SUFFIXEFFECTLIST,
				IB_ELDRITCHEFFECTFRAME, IB_ELDRITCHEFFECTLABEL, IB_ELDRITCHEFFECTLIST,
				IB_GSINVASIONELEMENTFRAME, IB_GSINVASIONELEMENTLABEL, IB_GSINVASIONELEMENTLIST,
				IB_GSINVASIONEFFECTFRAME, IB_GSINVASIONEFFECTLABEL, IB_GSINVASIONEFFECTLIST,
				IB_GSSUBJUGATIONELEMENTFRAME, IB_GSSUBJUGATIONELEMENTLABEL, IB_GSSUBJUGATIONELEMENTLIST,
				IB_GSSUBJUGATIONEFFECTFRAME, IB_GSSUBJUGATIONEFFECTLABEL, IB_GSSUBJUGATIONEFFECTLIST,
				IB_GSDEVASTATIONELEMENTFRAME, IB_GSDEVASTATIONELEMENTLABEL, IB_GSDEVASTATIONELEMENTLIST,
				IB_GSDEVASTATIONEFFECTFRAME, IB_GSDEVASTATIONEFFECTLABEL, IB_GSDEVASTATIONEFFECTLIST,
				IB_DTELDRITCHEFFECTFRAME, IB_DTELDRITCHEFFECTLABEL, IB_DTELDRITCHEFFECTLIST,
				IB_DTTEMPESTEFFECTFRAME, IB_DTTEMPESTEFFECTLABEL, IB_DTTEMPESTEFFECTLIST,
				IB_DTSOVEREIGNEFFECTFRAME, IB_DTSOVEREIGNEFFECTLABEL, IB_DTSOVEREIGNEFFECTLIST,
				IB_SHAVARATHELEMENTFRAME, IB_SHAVARATHELEMENTLABEL, IB_SHAVARATHELEMENTLIST, 
				IB_SHAVARATHEFFECTFRAME, IB_SHAVARATHEFFECTLABEL, IB_SHAVARATHEFFECTLIST, 
				IB_EPICFIRSTEFFECTFRAME, IB_EPICFIRSTEFFECTLABEL, IB_EPICFIRSTEFFECTLIST,
				IB_EPICSECONDEFFECTFRAME, IB_EPICSECONDEFFECTLABEL, IB_EPICSECONDEFFECTLIST, 
				IB_CURRENTDESCRIPTIONWINDOW, IB_BUILDDESCRIPTIONWINDOW, 
				ETD_CLOSEBUTTON, ETD_SAVEBUTTON, ETD_SAVEASBUTTON, ETD_LOADBUTTON, ETD_TEMPLATESELECTBOX, 
				ETD_EXAMPLEOUTPUTBOX, ETD_CODEINPUTBOX,
				EW_ACCEPTBUTTON, EW_CANCELBUTTON, EW_RESETALLTREESBUTTON, EW_APREMAININGLABEL, EW_APSPENTLABEL, EW_TREEFRAME1, EW_TREEFRAME2, EW_TREEFRAME3, EW_SELECTTREELIST, 
				MEW_ACCEPTBUTTON, MEW_CANCELBUTTON, MEW_SELECTIONFRAME,
				TTW_TOOLTIPTEXT,
				DW_ABILITIESLIST, DW_SHOWALLCHECKBOX, DW_ACCEPTBUTTON, DW_CANCELBUTTON, DW_DESTINIESFRAME, DW_ABILITIESFRAME, DW_ABILITIESLABEL, DW_DESTINIESLABEL, DW_TWISTSOFFATELABEL,
				DW_TWISTSOFFATEFRAME, DW_DESTINIESLIST, DW_ENFORCELEVELCHECKBOX, DW_ENFORCEDESTINYPROGRESSCHECKBOX,
				MFW_LABEL, MFW_ACCEPT, MFW_CANCEL, MFW_CLASSTEXT, MFW_SELECTEDPANEL, MFW_SELECTEDPANELLIST, MFW_SELECTEDPANELLABEL, MFW_FEATLISTPANEL, MFW_FEATLISTPANELLIST, MFW_FEATLISTPANELLABEL, MFW_FEATWISHPANEL,
				MFW_FEATWISHPANELLIST, MFW_FEATWISHPANELLABEL, MFW_DESCPANEL, MFW_SELECTPANEL, MFW_Add,MFW_Remove,MFW_CLEAR,
				MCL_LABEL, MCL_CLOSE, MCL_CLASSSTRING,	MCL_DESCRIPTION, MCL_CLASSFRAME, MCL_SELECTFRAME, MCL_LEVELLABEL, MCL_CLASSLABEL, MCL_CLASSLEVELLABEL, MCL_BABLABEL,
				MAB_LABEL, MAB_CLOSE, MAB_CREATIONFRAME, MAB_LEVELUPFRAME, MAB_CURRENTFRAME, MAB_TOMEFRAME, MAB_32BUILD, MAB_4STR, MAB_4DEX, MAB_4CON, MAB_4INT, MAB_4WIS, MAB_4CHA,
				MAB_8STR, MAB_8DEX, MAB_8CON, MAB_8INT, MAB_8WIS, MAB_8CHA, MAB_12STR, MAB_12DEX, MAB_12CON, MAB_12INT, MAB_12WIS, MAB_12CHA,
				MAB_16STR, MAB_16DEX, MAB_16CON, MAB_16INT, MAB_16WIS, MAB_16CHA, MAB_20STR, MAB_20DEX, MAB_20CON, MAB_20INT, MAB_20WIS, MAB_20CHA,
				MAB_24STR, MAB_24DEX, MAB_24CON, MAB_24INT, MAB_24WIS, MAB_24CHA, MAB_28STR, MAB_28DEX, MAB_28CON, MAB_28INT, MAB_28WIS, MAB_28CHA,
				MAB_CRESTR, MAB_CREDEX, MAB_CRECON, MAB_CREINT, MAB_CREWIS, MAB_CRECHA, MAB_LEVSTR, MAB_LEVDEX, MAB_LEVCON, MAB_LEVINT, MAB_LEVWIS, MAB_LEVCHA,
				MAB_CURSTR, MAB_CURDEX, MAB_CURCON, MAB_CURINT, MAB_CURWIS, MAB_CURCHA, MAB_TOMSTR, MAB_TOMDEX, MAB_TOMCON, MAB_TOMINT, MAB_TOMWIS, MAB_TOMCHA,
				MAB_CRESTR2, MAB_CREDEX2, MAB_CRECON2, MAB_CREINT2, MAB_CREWIS2, MAB_CRECHA2, MAB_LEVSTR2, MAB_LEVDEX2, MAB_LEVCON2, MAB_LEVINT2, MAB_LEVWIS2, MAB_LEVCHA2,
				MAB_CURSTR2, MAB_CURDEX2, MAB_CURCON2, MAB_CURINT2, MAB_CURWIS2, MAB_CURCHA2, MAB_TOMSTR2, MAB_TOMDEX2, MAB_TOMCON2, MAB_TOMINT2, MAB_TOMWIS2, MAB_TOMCHA2,
				MAB_AVAILIBLELABEL, MAB_AVAILABLEPOINTS, MAB_32LABEL, MAB_BASE, MAB_SPENT, MAB_COST, MAB_CREATIONLABEL, MAB_LEVELUPLABEL, MAB_LEVEL,
				MAB_L4, MAB_L8, MAB_L12, MAB_L16, MAB_L20, MAB_L24, MAB_L28, MAB_LTOTAL, MAB_CURRENTLABEL, MAB_VALUE, MAB_MOD, MAB_TOMELABEL, MAB_T1, MAB_T2, MAB_T3, MAB_T4,
				MAB_T5, MAB_T6, MAB_T7, MAB_TOMETOTAL, MAB_INSFRAME, MAB_INSLABEL, MAB_INSBOX,
				MSK_LABEL, MSK_ACCEPT, MSK_CANCEL, MSK_SKILLFRAME, MSK_RESET, MSK_TOTOALLABEL, MSK_SPENT, MSK_AVALIBLE, MSK_AUTOSKILLFRAME, MSK_AUTOSKILLCLASSFIRST, MSK_AUTOSKILLRESET, MSK_AUTOSKILLSET, MSK_AUTOSKILLTEXT, MSKAUTOSKILLRANK,
				MSP_LABEL, MSP_CANCEL};
enum CHILDWINDOW {MAINWINDOW, DATALOAD, ABOUTWINDOW, FORUMEXPORTWINDOW, ITEMBUILDERWINDOW, EXPORTTEMPLATEDESIGNWINDOW, PRINTWINDOW, ENHANCEMENTWINDOW, MULTIENHANCEMENTWINDOW, TOOLTIPWINDOW, DESTINYWINDOW, MULTIDESTINYWINDOW, MULTIFEATWINDOW,
				MULTICLASSWINDOW, MULTIABILITYWINDOW, MULTISKILLSWINDOW, MULTISPELLSWINDOW};

enum DATAFILE {RACEFILE, CLASSFILE, FEATFILE, SKILLFILE, ENHANCEMENTFILE, SPELLFILE, ITEMEFFECTFILE, ITEMCLICKYEFFECTFILE, ITEMFILE, TEMPLATEFILE, DESTINYFILE};
enum FILESTATE {FILEPENDING, FILELOADING, FILELOADED, FILEERROR};
enum ADVANCEMENTTYPE {ADV_UNKNOWN, ADV_RACEANDSEX, ADV_CLASS, ADV_NAMEANDALIGNMENT, ADV_REINCARNATE, ADV_ABILITYPOINT, ADV_ABILITYINCREASE, ADV_SKILLS, ADV_FEATS, ADV_SPELLS, ADV_TOME, ADV_ENHANCEMENTS};

enum SEX {MALE, FEMALE};
enum RACE {HUMAN, ELF, HALFLING, DWARF, WARFORGED, DROW, HALFELF, HALFORC, BLADEFORGED, MORNINGLORD, PURPLEDRAGONKNIGHT, SHADARKAI, GNOME, DEEPGNOME, RACENONE};
enum CLASS {FIGHTER, PALADIN, BARBARIAN, MONK, ROGUE, RANGER, CLERIC, WIZARD, SORCERER, BARD, FAVORED_SOUL, ARTIFICER, DRUID, WARLOCK, CLASSNONE};
enum ALIGNMENT {LAWFULGOOD, LAWFULNEUTRAL, NEUTRALGOOD, TRUENEUTRAL, CHAOTICGOOD, CHAOTICNEUTRAL, NOALIGNMENT};
enum ABILITIES {STRENGTH, DEXTERITY, CONSTITUTION, INTELLIGENCE, WISDOM, CHARISMA, ABILITYNONE};
enum ABILITYMODS {ABMOD_BASE, ABMOD_LEVELUP, ABMOD_INHERENT, ABMOD_FEATS, ABMOD_ENHANCEMENT, ABMOD_ENCHANTED, ABMOD_TOTAL};
enum FEATSLOTTYPE { FEATAUTOMATIC, FEATCHARACTER, FEATHUMANBONUS, FEATFIGHTERBONUS, FEATWIZARDBONUS, FEATRANGERFAVOREDENEMY, FEATROGUEBONUS, FEATMONKBONUS, FEATMONKPATH, FEATDEITY, FEATFAVOREDSOULBONUS, FEATPASTLIFE, FEATNONE, FEATSELECTED, FEATDERIVED, FEATHALFELFBONUS, FEATARTIFICERBONUS, FEATDRUIDWILDSHAPE, FEATDESTINY, FEATWARLOCKPACT, FEATLEGENDARY};
enum FEATAQUIRETYPE {FEATAQUIREAUTOMATIC, FEATAQUIREAUTONOPREREQ, FEATAQUIRETRAIN, FEATNOAQUIRE, FEATAQUIREANY};
enum FEATTAG {FEATTAGMETAMAGIC, FEATTAGFIGHTERBONUS, FEATTAGFAVOREDENEMY, FEATTAGROGUEBONUS, FEATTAGMONKBONUS, FEATTAGMONKPATH, FEATTAGDEITY, FEATTAGFAVOREDSOULBONUS, FEATTAGMULTIPLE, FEATTAGPARENTFEAT, FEATTAGPASTLIFE, FEATTAGHALFELFBONUS, FEATTAGMONKEXCLUSIVE, FEATTAGARTIFICERBONUS, FEATTAGDRUIDWILDSHAPE, FEATTAGDESTINY, FEATTAGDESTINYNOTEXCLUSIVE, FEATTAGWARLOCKPACT, FEATTAGLEGENDARY, FEATTAGNONE}; //Level Cap Increase
enum SKILLS {BALANCE, BLUFF, CONCENTRATION, DIPLOMACY, DISABLEDEVICE, HAGGLE, HEAL, HIDE, INTIMIDATE, JUMP, LISTEN, MOVESILENTLY, OPENLOCK, PERFORM, REPAIR, SEARCH, SPELLCRAFT, SPOT, SWIM, TUMBLE, UMD};
enum SPELLTYPE {SPELLAUTOMATIC, SPELLSELECTED, SPELLUNKNOWN};
enum SAVETYPE {FORTITUDESAVE, REFLEXSAVE, WILLSAVE};
enum SAVEMODS {SAVEMOD_BASE, SAVEMOD_ABILITY, SAVEMOD_FEATS, SAVEMOD_ENHANCEMENT, SAVEMOD_ENCHANTED, SAVEMOD_TOTAL};
enum ICONTYPE {RACEICON, CLASSICON, SKILLICON, FEATICON, ENHANCEMENTICON, SPELLICON};
enum EQUIPMENTSLOTTYPE {RIGHTHANDSLOT, LEFTHANDSLOT, AMMOSLOT, FACESLOT, ARMORSLOT, BRACERSLOT, LEFTRINGSLOT, HEADSLOT, FEETSLOT, NECKSLOT, GLOVESSLOT, TRINKETSLOT, BACKSLOT, WAISTSLOT, RIGHTRINGSLOT, QUIVERSLOT, NOSLOT};
enum EQUIPMENTMODTYPE {EQUIPCOMPETENCE, EQUIPENHANCEMENT, EQUIPLUCK, EQUIPRESISTANCE, EQUIPINSIGHT, EQUIPPENALTY};
enum ACMODS {ACMOD_BASE, ACMOD_ARMOR, ACMOD_SHIELD, ACMOD_DEX, ACMOD_WIS, ACMOD_NATURAL, ACMOD_SIZE, ACMOD_LUCK, ACMOD_DEFLECTION, ACMOD_INSIGHT, ACMOD_CENTERED, ACMOD_MISC, ACMOD_DODGE, ACMOD_TOTAL};
enum PREREQRESULT {PREREQ_DISQUALIFY, PREREQ_FAIL, PREREQ_COST_FAIL, PREREQ_PASS};
//Enhancement Stuff
enum ENHANCEMENT_TREE {ENHT_BLADEFORGED, ENHT_DROW, ENHT_DWARF, ENHT_ELF, ENHT_HALFLING, ENHT_HALF_ELF,
						ENHT_HALF_ORC, ENHT_HUMAN, ENHT_MORNINGLORD, ENHT_PURPLE_DRAGON_KNIGHT, ENHT_SHADAR_KAI, ENHT_WARFORGED,
						ENHT_AIR_SAVANT_SOR, ENHT_ANGEL_OF_VENGEANCE_FVS, ENHT_ARCANE_ARCHER_ELF, ENHT_ARCANE_ARCHER_RNG, ENHT_ARCANOTECHNICIAN_ART, ENHT_ARCHMAGE_WIZ,
						ENHT_ASSASSIN_ROG, ENHT_BATTLE_ENGINEER_ART, ENHT_DEEPWOOD_STALKER_RNG, ENHT_DIVINE_DISCIPLE_CLR, ENHT_EARTH_SAVANT_SOR, ENHT_ELDRITCH_KNIGHT_SOR, ENHT_ELDRITCH_KNIGHT_WIZ,
						ENHT_FIRE_SAVANT_SOR,
						ENHT_FRENZIED_BERSERKER_BAR, ENHT_HENSHIN_MYSTIC_MNK, ENHT_KENSEI_FTR, ENHT_KNIGHT_OF_THE_CHALICE_PAL, ENHT_MECHANIC_ROG, ENHT_NATURES_WARRIOR_DRD,
						ENHT_NINJA_SPY_MNK, ENHT_OCCULT_SLAYER_BAR, ENHT_PALE_MASTER_WIZ, ENHT_RADIANT_SERVANT_CLR, ENHT_RAVAGER_BAR,
						ENHT_SACRED_DEFENDER_PAL, ENHT_SEASONS_HERALD_DRD, ENHT_SHINTAO_MNK, ENHT_SPELLSINGER_BRD, ENHT_STALWART_DEFENDER_FTR, ENHT_TEMPEST_RNG, ENHT_THIEF_ACROBAT_ROG,
						ENHT_WARCHANTER_BRD, ENHT_WARPRIEST_CLR, ENHT_WARPRIEST_FVS, ENHT_WATER_SAVANT_SOR, ENHT_VANGUARD_FTR, ENHT_VANGUARD_PAL, ENHT_SWASHBUCKLER_BRD, ENHT_HARPER_AGENT,
						ENHT_SOULEATER_WLK, ENHT_TANTEDSCHOLAR_WLK, ENHT_ENLIGHTENEDSPIRIT_WLK, ENHT_GNOME, ENHT_DEEPGNOME,
						ENHT_UNKNOWN, ENHT_UNSET, ENHT_NOTREE, ENHT_FUTURETREE};
enum ENHANCEMENT_TREE_TYPE {ENHTT_CLASS, ENHTT_RACE, ENHTT_SPECIAL, ENHTT_UI};
enum ENH_REQTYPE {ENH_ENHANCEMENT, ENH_FEAT, ENH_MULTIENHANCEMENT, ENH_CLASS, ENH_UNKNOWN};
//Destiny Stuff
enum DESTINY_TREE {DT_UNKNOWN, DT_NONE, DT_DRACONIC_INCARNATION, DT_FATESINGER, DT_MAGISTER, DT_EXALTED_ANGEL, DT_UNYIELDING_SENTINEL, DT_GRANDMASTER_OF_FLOWERS, DT_LEGENDARY_DREADNAUGHT,
					DT_SHADOWDANCER, DT_FURY_OF_THE_WILD, DT_PRIMAL_AVATAR, DT_SHIRADI_CHAMPION};
enum DESTINY_REQTYPE {D_DESTINY, D_MULTIDESTINY, D_FEAT, D_CLASS, D_UNKNOWN};
enum DESTINY_SPHERE {DS_ARCANE, DS_DIVINE, DS_MARTIAL, DS_PRIMAL, DS_NONE};
//Enhancement and Destiny stuff
enum ARROW_DIRECTION {AD_LEFT, AD_RIGHT, AD_UP};

// Added this one in to combine all the modtypes into one
// don't see a reason to have separate ones unless i'm missing something.
enum MODTYPE {NOMOD, ALCHEMICALMOD, ARMORMOD, BONUSMOD, COMPETENCEMOD, DEFLECTIONMOD, DODGEMOD, ENHANCEMENTMOD, EXCEPTIONALMOD, INSIGHTMOD, LUCKMOD, MAXIMUMMOD, MISCMOD, NATURALMOD, PENALTYMOD, PROFANEMOD, RESISTANCEMOD, SHIELDMOD, TOUGHNESSMOD, ELEMENTALMOD, IMPROVEDELEMENTALMOD, GREATERELEMENTALMOD, PIRATEMOD, EPICMOD};
enum MODCATEGORY {MC_ABILITY, MC_ATTRIBUTE, MC_RESISTANCE, MC_SAVE, MC_SKILL, MC_UNKNOWN};
enum EFFECTTYPE {BONUS, MATERIAL, PREFIX, SUFFIX, GSINVASION, INVASIONELEMENT, GSSUBJUGATION, SUBJUGATIONELEMENT, GSDEVASTATION, DEVASTATIONELEMENT, DTELDRITCH, DTTEMPEST, DTSOVEREIGN, ELDRITCH, SHAVARATHELEMENT, SHAVARATHEFFECT, EPICEFFECT};
enum ITEMTYPE {PADDEDARMOR, LEATHERARMOR, STUDDEDLEATHERARMOR, CHAINSHIRTARMOR,
				HIDEARMOR, SCALEMAILARMOR, CHAINMAILARMOR, BREASTPLATEARMOR, BRIGADINEARMOR,
				SPLINTMAILARMOR, BANDEDMAILARMOR, HALFPLATEARMOR, FULLPLATEARMOR,
				ROBE, DOCENT, 
				SMALLSHIELD, LARGESHIELD, TOWERSHIELD, BUCKLER, 
				GOGGLES, HELMET, NECKLACE, TRINKETITEM, CLOAK, BELT, RING, GLOVESITEM, BOOTS, BRACERS, QUIVER, 
				BASTARDSWORD, BATTLEAXE, CLUB, DAGGER, DART, DWARVENWARAXE, FALCHION, GREATAXE, GREATCLUB, GREATCROSSBOW, 
				GREATSWORD, HANDAXE, HANDWRAPS, HEAVYCROSSBOW, HEAVYMACE, HEAVYPICK, KAMA, KHOPESH, KUKRI, LIGHTCROSSBOW, 
				LIGHTHAMMER, LIGHTMACE, LIGHTPICK, LONGBOW, LONGSWORD, MAUL, MORNINGSTAR, QUARTERSTAFF, RAPIER, 
				REPEATINGHEAVYCROSSBOW, REPEATINGLIGHTCROSSBOW, SCIMITAR, SHORTBOW, SHORTSWORD, SHURIKEN, SICKLE, 
				THROWINGAXE, THROWINGDAGGER, THROWINGHAMMER, WARHAMMER,
				ARROW, BOLT};
enum ITEMBASETYPE {GENERIC, NAMED, GREENSTEEL, DRAGONTOUCHED, SHAVARATHRING, EPIC};
enum GSELEMENTTYPE {NOEFFECT, AIR, AEARTH, AFIRE, ANEG, APOS, AWATER, 
					EARTH, EAIR, EFIRE, ENEG, EPOS, EWATER, 
					FIRE, FAIR, FEARTH, FNEG, FPOS, FWATER, 
					NEGATIVE, NAIR, NEARTH, NFIRE, NPOS, NWATER, 
					POSITIVE, PAIR, PEARTH, PFIRE, PNEG, PWATER, 
					WATER, WAIR, WEARTH, WFIRE, WNEG, WPOS, 
					NOBONUS, ASH, BOLAS, DUST, ICE, LIGHTNING, MAGMA, MINERAL, OOZE, RADIANCE, SALT, SMOKE, STALEMATE, STEAM, TEMPERED, VACUUM};
enum EPICSLOTCOLOR {NONCOLOR, BLUE, COLORLESS, GREEN, ORANGE, RED, VIOLET, YELLOW};
enum ICONICRACES{FEAT_BLADEFORGED, FEAT_MORNINGLORD, FEAT_PURPLEDRAGONKNIGHT, FEAT_SHADARKAI, FEAT_DEEPGNOME};
enum ARCANEFEAT{ENERGY_CRITICALS,ENCH_WEAP,ARCANE_ALACRITY};
enum DIVINEFEAT{POWER_OLD,BRACE,BLOCK_ENERGY};
enum MARTIALFEAT{DOUBLESTRIKE, SKILL_MASTERY,FORT};
enum PRIMALFEAT{DOUBLE_SHOT,FAST_HEAL,COLORS_QUEEN};

//structures used by more than one class
struct GraphicStruct
    {
    string Name;
    HBITMAP Graphic;
    HBITMAP Mask;
    int Width;
    int Height;
    };

struct CharacterItemStruct
{
	unsigned int ItemIndex;
	//vector <unsigned int> ItemEffects; // holder for Item effects of any type
	unsigned int ItemEffect1; // holder for Bonus, Greensteel Element 1, Dragontouched 1 & Ring Effects
	unsigned int ItemEffect2; // holder for Material, Greensteel 1 & Dragontouched Tempest Effects
	unsigned int ItemEffect3; // holder for Prefix, Greensteel Element 2 & Dragontouched Sovergin Effects
	unsigned int ItemEffect4; // holder for Suffix Effects & Greensteel 2
	unsigned int ItemEffect5; // holder for Greensteel Element 3
	unsigned int ItemEffect6; // holder for Greensteel 3
	unsigned int Eldritch;
};

struct ArrowStruct
	{
	unsigned int Level;
	unsigned int Slot;
	ARROW_DIRECTION Direction;
	unsigned int Length;
	};

struct ParentHeadingStruct
{
	string ParentHeading;
	bool Collapsed;
	unsigned int ListIndex;
};

#ifdef _DEBUG
#define DEBUG(X) {ostringstream  ss("DEBUG: "); \
                 ss << __FUNCTION__ << " [" << GetTickCount() << "]: " << X << endl; \
				 OutputDebugString(ss.str().c_str());}
#else
#define DEBUG(X)
#endif

#endif
