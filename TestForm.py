import uno
from com.sun.star.beans import PropertyValue

def save_to_calc(name, nomorid, jenis, harga):
    # Connect to a running LibreOffice instance
    local_context = uno.getComponentContext()
    resolver = local_context.ServiceManager.createInstanceWithContext(
        "com.sun.star.bridge.UnoUrlResolver", local_context)
    ctx = resolver.resolve("uno:socket,host=localhost,port=2002;urp;StarOffice.ComponentContext")
    smgr = ctx.ServiceManager
    desktop = smgr.createInstanceWithContext("com.sun.star.frame.Desktop", ctx)
    
    # Create a new Calc document
    doc = desktop.loadComponentFromURL(
        "private:factory/scalc", "_blank", 0, ())
    sheet = doc.Sheets.getByIndex(0)

    # Write data to the Calc document
    cell_range = sheet.getCellRangeByName("A1:D1")
    data = [nama, nomorid, jenis, harga]
    cell_range.setDataArray([data])

    # Save the document as an ODS file
    prop_vals = (PropertyValue("FilterName", 0, "calc8"),)
    doc.storeToURL("file:///path/to/your/folder/form_data.ods", prop_vals)

if __name__ == "__main__":
    import cgi
    form = cgi.FieldStorage()
    nama = form.getvalue("nama")
    nomorid = form.getvalue("id")
    jenis = form.getvalue("jenis")
    harga = form.getvalue("harga")

    save_to_calc(nama, nomorid, jenis, harga)

    # Redirect back to the form
    print("Content-type: text/html\n")
    print("<html>")
    print("<head>")
    print('<meta http-equiv="refresh" content="0;url=FormHTML.html">')
    print("</head>")
    print("<body>")
    print("</body>")
    print("</html>")