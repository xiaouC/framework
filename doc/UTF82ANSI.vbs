aCode = "UTF-8"
bCode = "GB2312"
Set objArgs = WScript.Arguments

FileUrlSrc = objArgs(0)
FileUrlDst = objArgs(1)
Call WriteToFile(FileUrlDst, ReadFile(FileUrlSrc, aCode), bCode)

Function ReadFile(FileUrlSrc, CharSet)
    Dim Str
    Set stm = CreateObject("Adodb.Stream")
    stm.Type = 2
    stm.mode = 3
    stm.charset = CharSet
    stm.Open
    stm.loadfromfile FileUrlSrc
    Str = stm.readtext
    stm.Close
    Set stm = Nothing
    ReadFile = Str
End Function

Function WriteToFile (FileUrlDst, Str, CharSet)
    Set stm = CreateObject("Adodb.Stream")
    stm.Type = 2
    stm.mode = 3
    stm.charset = CharSet
    stm.Open
    stm.WriteText Str
    stm.SaveToFile FileUrlDst, 2
    stm.flush
    stm.Close
    Set stm = Nothing
End Function