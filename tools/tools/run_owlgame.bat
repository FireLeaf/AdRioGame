@set SrcRoot=E:\AdRioGame\lottery\
@echo Src Root is:
@echo %SrcRoot%
@echo build project code:
@echo copy asset:"
@xcopy %SrcRoot%res %SrcRoot%runtime\win32\init_asset\res /a /e /f /y
@echo copy lua code:
@if exist %SrcRoot%runtime\win32\init_asset\src\cocos\*.lua (
	xcopy %SrcRoot%src\app %SrcRoot%runtime\win32\init_asset\src\app /a /e /f /y
) else (
	xcopy %SrcRoot%src %SrcRoot%runtime\win32\init_asset\src /a /e /f /y
)
@start %SrcRoot%runtime/win32/lottery.exe
@pause