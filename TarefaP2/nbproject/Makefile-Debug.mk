#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Teste1.o \
	${OBJECTDIR}/Teste2.o \
	${OBJECTDIR}/Teste3.o \
	${OBJECTDIR}/context/contexts.o \
	${OBJECTDIR}/context/ucontext.o \
	${OBJECTDIR}/context/ucontext.o \
	${OBJECTDIR}/context/ucontext_asm.o \
	${OBJECTDIR}/contexts.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/ppos_core.o \
	${OBJECTDIR}/queue.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tarefap2

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tarefap2: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tarefap2 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Teste1.o: Teste1.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Teste1.o Teste1.c

${OBJECTDIR}/Teste2.o: Teste2.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Teste2.o Teste2.c

${OBJECTDIR}/Teste3.o: Teste3.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Teste3.o Teste3.c

${OBJECTDIR}/context/contexts.o: context/contexts.c
	${MKDIR} -p ${OBJECTDIR}/context
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/context/contexts.o context/contexts.c

${OBJECTDIR}/context/ucontext.o: context/ucontext.c
	${MKDIR} -p ${OBJECTDIR}/context
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/context/ucontext.o context/ucontext.c

${OBJECTDIR}/context/ucontext.o: context/ucontext.s
	${MKDIR} -p ${OBJECTDIR}/context
	$(AS) $(ASFLAGS) -g -o ${OBJECTDIR}/context/ucontext.o context/ucontext.s

${OBJECTDIR}/context/ucontext_asm.o: context/ucontext_asm.S
	${MKDIR} -p ${OBJECTDIR}/context
	$(AS) $(ASFLAGS) -g -o ${OBJECTDIR}/context/ucontext_asm.o context/ucontext_asm.S

${OBJECTDIR}/contexts.o: contexts.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/contexts.o contexts.c

${OBJECTDIR}/main.o: main.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/ppos_core.o: ppos_core.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ppos_core.o ppos_core.c

${OBJECTDIR}/queue.o: queue.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/queue.o queue.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
