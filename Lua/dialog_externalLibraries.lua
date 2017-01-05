require("iuplua")   --external modules using require function

ml=iup.multiline
   {
   expand="yes",
   value="the dialog context show in the dialog.",
   border="yes"
   }
 dlg=iup.dialog{ml;title="dialogName",}
  dlg:show()
  iup.MainLoop()



