using System;
using System.Diagnostics;
using System.Drawing.Printing;
using System.Windows.Forms;

using System.Drawing.PieChart;

namespace TestPieChart {

    public class PrintChart {

        public PrintChart(PieChart3D pieChart) {
            m_pieChart = pieChart;
		}

        public void DoPrint(PrintDocument pd) {
            try {
                pd.PrintPage += new PrintPageEventHandler(pd_PrintPage);
                pd.Print();
            } 
            catch(Exception ex) { 
                MessageBox.Show(ex.Message);
            }
        }

        private void pd_PrintPage(object sender, PrintPageEventArgs ev) {
            ev.Graphics.CompositingQuality = System.Drawing.Drawing2D.CompositingQuality.HighQuality;
            ev.Graphics.InterpolationMode = System.Drawing.Drawing2D.InterpolationMode.High;
            m_pieChart.Draw(ev.Graphics);
            m_pieChart.PlaceTexts(ev.Graphics);
            ev.HasMorePages = false;
        }

        private PieChart3D m_pieChart = null;
	}
}