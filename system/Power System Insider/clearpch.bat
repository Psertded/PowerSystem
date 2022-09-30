@echo off
del /s /q .\.vs\PSYSTEM\v17\ipch\AutoPCH\*
rmdir /r /d.\.vs\PSYSTEM\v17\ipch\AutoPCH
dir .\.vs\PSYSTEM\v17\ipch\AutoPCH\*
pause