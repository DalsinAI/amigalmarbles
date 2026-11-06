/* A Shell gives 4 KB of stack; libnix's startup sets this much up instead.
 * The AmiCradle Team. GPL 2 or later, like LMarbles. */
unsigned long __stack = 256 * 1024;
static const char version[] __attribute__((used)) = "$VER: LMarbles 1.1.2 Amiga (06.11.2026)";
