perl -h >nul 2>&1
set lastError=%ERRORLEVEL%
IF %lastError% == 1 (
 ECHO perl 5.16 should been installed !
 pause
 EXIT 1
) 

set IDE_VS2010="%VS100COMNTOOLS%/../IDE/Devenv"

%IDE_VS2010% "bgcc.sln" /rebuild Release /project bgcc
%IDE_VS2010% "bgcc.sln" /build Debug /project bgcc

%IDE_VS2010% "bgcc.sln" /rebuild Release /project bgcc-MD
%IDE_VS2010% "bgcc.sln" /rebuild Debug /project bgcc-MD

%IDE_VS2010% "bgcc.sln" /build Release /project bidl2sl
