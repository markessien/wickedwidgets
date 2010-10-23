
WickedWidgetsps.dll: dlldata.obj WickedWidgets_p.obj WickedWidgets_i.obj
	link /dll /out:WickedWidgetsps.dll /def:WickedWidgetsps.def /entry:DllMain dlldata.obj WickedWidgets_p.obj WickedWidgets_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del WickedWidgetsps.dll
	@del WickedWidgetsps.lib
	@del WickedWidgetsps.exp
	@del dlldata.obj
	@del WickedWidgets_p.obj
	@del WickedWidgets_i.obj
