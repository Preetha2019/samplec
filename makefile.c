##### Module Macro #####
NAME = twofile
SRCS = twofile1.c twofile2.c
OBJS =
##### C7 Macro (if you have Microsoft C-7) #####
C7 = 1
##### Library Macros (if programming under Windows) #####
LIBS = libw mlibcew
MOD = -AM
##### Include Macro #####
INCLS = $(NAME).h define.h typedef.h vars.h prototyp.h
#### DEBUG Defined #####
DEBUG = 1
##### Build Option Macros #####
!if $(DEBUG)
DDEF = -DDEBUG
CLOPT = -Zid -Od
MOPT = -Zi
LOPT = /CO /LI /MAP
!else
DDEF =
CLOPT = -Os
LOPT =
!endif
##### General Macro #####
DEF =
##### Tool Macros #####
ASM = masm -Mx $(MOPT) $(DDEF) $(DEF)
CC = cl -nologo -c $(MOD) -G2sw -Zp -W3 $(CLOPT) $(DDEF) $(DEF)
LINK = link /NOD /NOE $(LOPT)
RC = rc $(DDEF) $(DEF)
HC = hc
##### Inference Rules #####
.c.obj:
$(CC) $*.c
.asm.obj:
$(ASM) $*.asm;
.rc.res:
$(RC) -r $*.rc
##### Main (default) Target #####
goal: $(NAME).exe
##### Dependents For Goal and Command Lines #####
$(NAME).exe: $(SRCS:.c=.obj)
$(LINK) @<<
$(SRCS:.c=.obj) $(OBJS),
$(NAME).exe,
$(NAME).map,
$(LIBS),
$(NAME).def
<<
!if $(DEBUG)
!if !$(C7)
cvpack -p $(NAME).exe
!endif
mapsym $(NAME).map
!endif
##### Dependents #####
$(SRCS:.c=.obj): $(INCLS)
##### Clean Directory #####
clean:
-del *.obj
-del *.exe