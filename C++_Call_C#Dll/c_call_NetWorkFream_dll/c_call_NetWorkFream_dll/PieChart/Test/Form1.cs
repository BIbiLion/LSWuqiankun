using System;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Drawing.Printing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;

using System.Drawing.PieChart;

namespace TestPieChart {
	/// <summary>
	/// Summary description for Form1.
	/// </summary>
	public class Form1 : System.Windows.Forms.Form	{

        #region Controls

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.CheckBox checkBox1;
        private System.Windows.Forms.CheckBox checkBox2;
        private System.Windows.Forms.CheckBox checkBox3;
        private System.Windows.Forms.CheckBox checkBox4;
        private System.Windows.Forms.CheckBox checkBox5;
        private System.Windows.Forms.CheckBox checkBox6;
        private System.Windows.Forms.NumericUpDown numericUpDownValue1;
        private System.Windows.Forms.NumericUpDown numericUpDownValue2;
        private System.Windows.Forms.NumericUpDown numericUpDownValue3;
        private System.Windows.Forms.NumericUpDown numericUpDownValue4;
        private System.Windows.Forms.NumericUpDown numericUpDownValue5;
        private System.Windows.Forms.NumericUpDown numericUpDownValue6;
        private System.Windows.Forms.NumericUpDown numericUpDownDisplacement1;
        private System.Windows.Forms.NumericUpDown numericUpDownDisplacement2;
        private System.Windows.Forms.NumericUpDown numericUpDownDisplacement3;
        private System.Windows.Forms.NumericUpDown numericUpDownDisplacement4;
        private System.Windows.Forms.NumericUpDown numericUpDownDisplacement5;
        private System.Windows.Forms.NumericUpDown numericUpDownDisplacement6;
        private System.Windows.Forms.Button buttonColor1;
        private System.Windows.Forms.Button buttonColor2;
        private System.Windows.Forms.Button buttonColor3;
        private System.Windows.Forms.Button buttonColor4;
        private System.Windows.Forms.Button buttonColor5;
        private System.Windows.Forms.Button buttonColor6;
        private System.Windows.Forms.TextBox textBoxText1;
        private System.Windows.Forms.TextBox textBoxText2;
        private System.Windows.Forms.TextBox textBoxText3;
        private System.Windows.Forms.TextBox textBoxText5;
        private System.Windows.Forms.TextBox textBoxText4;
        private System.Windows.Forms.TextBox textBoxText6;
        private System.Windows.Forms.TextBox textBoxToolTip1;
        private System.Windows.Forms.TextBox textBoxToolTip2;
        private System.Windows.Forms.TextBox textBoxToolTip3;
        private System.Windows.Forms.TextBox textBoxToolTip4;
        private System.Windows.Forms.TextBox textBoxToolTip5;
        private System.Windows.Forms.TextBox textBoxToolTip6;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.NumericUpDown numericUpDownLeftMargin;
        private System.Windows.Forms.NumericUpDown numericUpDownRightMargin;
        private System.Windows.Forms.NumericUpDown numericUpDownTopMargin;
        private System.Windows.Forms.NumericUpDown numericUpDownBottomMargin;
        private System.Windows.Forms.NumericUpDown numericUpDownAngle;
        private System.Windows.Forms.NumericUpDown numericUpDownPieHeight;
        private System.Windows.Forms.ComboBox comboBoxEdgeType;
        private System.Windows.Forms.GroupBox groupBox6;
        private System.Windows.Forms.RadioButton radioButtonShadowStyleGradual;
        private System.Windows.Forms.RadioButton radioButtonShadowStyleUniform;
        private System.Windows.Forms.RadioButton radioButtonShadowStyleNone;
        private System.Windows.Forms.NumericUpDown numericUpDownEdgeLineWidth;
        private System.Windows.Forms.CheckBox checkBoxFitChart;
        private System.Windows.Forms.NumericUpDown m_numericUpDownAlpha;

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Label label14;

        private System.Windows.Forms.Button m_buttonPrint;

        private System.Windows.Forms.PrintDialog m_printDialog;
        private System.Windows.Forms.ColorDialog m_colorDialog;
        #endregion
        private PieChartControl m_panelDrawing;

		private System.ComponentModel.Container components = null;

		public Form1() {
			InitializeComponent();
            FillEdgeColorTypeListBox();
            InitializeChart();
		}
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		protected override void Dispose(bool disposing) {
			if (disposing) {
				if (components != null) {
					components.Dispose();
				}
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
            this.numericUpDownAngle = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.radioButtonShadowStyleGradual = new System.Windows.Forms.RadioButton();
            this.radioButtonShadowStyleUniform = new System.Windows.Forms.RadioButton();
            this.radioButtonShadowStyleNone = new System.Windows.Forms.RadioButton();
            this.numericUpDownValue6 = new System.Windows.Forms.NumericUpDown();
            this.numericUpDownValue5 = new System.Windows.Forms.NumericUpDown();
            this.numericUpDownValue4 = new System.Windows.Forms.NumericUpDown();
            this.numericUpDownValue3 = new System.Windows.Forms.NumericUpDown();
            this.numericUpDownValue2 = new System.Windows.Forms.NumericUpDown();
            this.numericUpDownValue1 = new System.Windows.Forms.NumericUpDown();
            this.numericUpDownDisplacement1 = new System.Windows.Forms.NumericUpDown();
            this.numericUpDownDisplacement6 = new System.Windows.Forms.NumericUpDown();
            this.numericUpDownDisplacement5 = new System.Windows.Forms.NumericUpDown();
            this.numericUpDownDisplacement4 = new System.Windows.Forms.NumericUpDown();
            this.numericUpDownDisplacement3 = new System.Windows.Forms.NumericUpDown();
            this.numericUpDownDisplacement2 = new System.Windows.Forms.NumericUpDown();
            this.numericUpDownPieHeight = new System.Windows.Forms.NumericUpDown();
            this.label2 = new System.Windows.Forms.Label();
            this.comboBoxEdgeType = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.numericUpDownBottomMargin = new System.Windows.Forms.NumericUpDown();
            this.numericUpDownTopMargin = new System.Windows.Forms.NumericUpDown();
            this.numericUpDownRightMargin = new System.Windows.Forms.NumericUpDown();
            this.numericUpDownLeftMargin = new System.Windows.Forms.NumericUpDown();
            this.label7 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.buttonColor6 = new System.Windows.Forms.Button();
            this.buttonColor5 = new System.Windows.Forms.Button();
            this.buttonColor4 = new System.Windows.Forms.Button();
            this.buttonColor3 = new System.Windows.Forms.Button();
            this.buttonColor2 = new System.Windows.Forms.Button();
            this.buttonColor1 = new System.Windows.Forms.Button();
            this.m_colorDialog = new System.Windows.Forms.ColorDialog();
            this.groupBox6 = new System.Windows.Forms.GroupBox();
            this.textBoxText6 = new System.Windows.Forms.TextBox();
            this.textBoxText5 = new System.Windows.Forms.TextBox();
            this.textBoxText4 = new System.Windows.Forms.TextBox();
            this.textBoxText3 = new System.Windows.Forms.TextBox();
            this.textBoxText2 = new System.Windows.Forms.TextBox();
            this.textBoxText1 = new System.Windows.Forms.TextBox();
            this.label14 = new System.Windows.Forms.Label();
            this.textBoxToolTip6 = new System.Windows.Forms.TextBox();
            this.textBoxToolTip5 = new System.Windows.Forms.TextBox();
            this.textBoxToolTip4 = new System.Windows.Forms.TextBox();
            this.textBoxToolTip3 = new System.Windows.Forms.TextBox();
            this.textBoxToolTip2 = new System.Windows.Forms.TextBox();
            this.textBoxToolTip1 = new System.Windows.Forms.TextBox();
            this.label12 = new System.Windows.Forms.Label();
            this.checkBox6 = new System.Windows.Forms.CheckBox();
            this.checkBox5 = new System.Windows.Forms.CheckBox();
            this.checkBox4 = new System.Windows.Forms.CheckBox();
            this.checkBox3 = new System.Windows.Forms.CheckBox();
            this.checkBox2 = new System.Windows.Forms.CheckBox();
            this.checkBox1 = new System.Windows.Forms.CheckBox();
            this.label10 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.numericUpDownEdgeLineWidth = new System.Windows.Forms.NumericUpDown();
            this.checkBoxFitChart = new System.Windows.Forms.CheckBox();
            this.label13 = new System.Windows.Forms.Label();
            this.m_numericUpDownAlpha = new System.Windows.Forms.NumericUpDown();
            this.m_buttonPrint = new System.Windows.Forms.Button();
            this.m_printDialog = new System.Windows.Forms.PrintDialog();
            this.m_panelDrawing = new System.Drawing.PieChart.PieChartControl();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownAngle)).BeginInit();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownValue6)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownValue5)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownValue4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownValue3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownValue2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownValue1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownDisplacement1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownDisplacement6)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownDisplacement5)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownDisplacement4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownDisplacement3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownDisplacement2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownPieHeight)).BeginInit();
            this.groupBox4.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownBottomMargin)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownTopMargin)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownRightMargin)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownLeftMargin)).BeginInit();
            this.groupBox6.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownEdgeLineWidth)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.m_numericUpDownAlpha)).BeginInit();
            this.SuspendLayout();
            // 
            // numericUpDownAngle
            // 
            this.numericUpDownAngle.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.numericUpDownAngle.Increment = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.numericUpDownAngle.Location = new System.Drawing.Point(490, 382);
            this.numericUpDownAngle.Maximum = new decimal(new int[] {
            400,
            0,
            0,
            0});
            this.numericUpDownAngle.Minimum = new decimal(new int[] {
            360,
            0,
            0,
            -2147483648});
            this.numericUpDownAngle.Name = "numericUpDownAngle";
            this.numericUpDownAngle.Size = new System.Drawing.Size(57, 21);
            this.numericUpDownAngle.TabIndex = 7;
            this.numericUpDownAngle.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.numericUpDownAngle.Value = new decimal(new int[] {
            30,
            0,
            0,
            -2147483648});
            this.numericUpDownAngle.ValueChanged += new System.EventHandler(this.numericUpDownAngle_ValueChanged);
            // 
            // label1
            // 
            this.label1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label1.Location = new System.Drawing.Point(403, 384);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(87, 18);
            this.label1.TabIndex = 6;
            this.label1.Text = "Initial angle:";
            // 
            // groupBox1
            // 
            this.groupBox1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.groupBox1.Controls.Add(this.radioButtonShadowStyleGradual);
            this.groupBox1.Controls.Add(this.radioButtonShadowStyleUniform);
            this.groupBox1.Controls.Add(this.radioButtonShadowStyleNone);
            this.groupBox1.Location = new System.Drawing.Point(576, 320);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(125, 88);
            this.groupBox1.TabIndex = 8;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Shadow style";
            // 
            // radioButtonShadowStyleGradual
            // 
            this.radioButtonShadowStyleGradual.Checked = true;
            this.radioButtonShadowStyleGradual.Location = new System.Drawing.Point(19, 62);
            this.radioButtonShadowStyleGradual.Name = "radioButtonShadowStyleGradual";
            this.radioButtonShadowStyleGradual.Size = new System.Drawing.Size(96, 18);
            this.radioButtonShadowStyleGradual.TabIndex = 2;
            this.radioButtonShadowStyleGradual.TabStop = true;
            this.radioButtonShadowStyleGradual.Tag = "";
            this.radioButtonShadowStyleGradual.Text = "&Gradual";
            this.radioButtonShadowStyleGradual.CheckedChanged += new System.EventHandler(this.radioButtonShadowStyle_Changed);
            // 
            // radioButtonShadowStyleUniform
            // 
            this.radioButtonShadowStyleUniform.Location = new System.Drawing.Point(19, 41);
            this.radioButtonShadowStyleUniform.Name = "radioButtonShadowStyleUniform";
            this.radioButtonShadowStyleUniform.Size = new System.Drawing.Size(96, 17);
            this.radioButtonShadowStyleUniform.TabIndex = 1;
            this.radioButtonShadowStyleUniform.Tag = "";
            this.radioButtonShadowStyleUniform.Text = "&Uniform";
            this.radioButtonShadowStyleUniform.CheckedChanged += new System.EventHandler(this.radioButtonShadowStyle_Changed);
            // 
            // radioButtonShadowStyleNone
            // 
            this.radioButtonShadowStyleNone.Location = new System.Drawing.Point(19, 19);
            this.radioButtonShadowStyleNone.Name = "radioButtonShadowStyleNone";
            this.radioButtonShadowStyleNone.Size = new System.Drawing.Size(96, 18);
            this.radioButtonShadowStyleNone.TabIndex = 0;
            this.radioButtonShadowStyleNone.Tag = "";
            this.radioButtonShadowStyleNone.Text = "&None";
            this.radioButtonShadowStyleNone.CheckedChanged += new System.EventHandler(this.radioButtonShadowStyle_Changed);
            // 
            // numericUpDownValue6
            // 
            this.numericUpDownValue6.Location = new System.Drawing.Point(38, 232);
            this.numericUpDownValue6.Name = "numericUpDownValue6";
            this.numericUpDownValue6.Size = new System.Drawing.Size(48, 21);
            this.numericUpDownValue6.TabIndex = 36;
            this.numericUpDownValue6.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.numericUpDownValue6.Value = new decimal(new int[] {
            25,
            0,
            0,
            0});
            this.numericUpDownValue6.ValueChanged += new System.EventHandler(this.numericUpDownValue_ValueChanged);
            // 
            // numericUpDownValue5
            // 
            this.numericUpDownValue5.Location = new System.Drawing.Point(38, 194);
            this.numericUpDownValue5.Name = "numericUpDownValue5";
            this.numericUpDownValue5.Size = new System.Drawing.Size(48, 21);
            this.numericUpDownValue5.TabIndex = 30;
            this.numericUpDownValue5.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.numericUpDownValue5.Value = new decimal(new int[] {
            25,
            0,
            0,
            0});
            this.numericUpDownValue5.ValueChanged += new System.EventHandler(this.numericUpDownValue_ValueChanged);
            // 
            // numericUpDownValue4
            // 
            this.numericUpDownValue4.Location = new System.Drawing.Point(38, 156);
            this.numericUpDownValue4.Name = "numericUpDownValue4";
            this.numericUpDownValue4.Size = new System.Drawing.Size(48, 21);
            this.numericUpDownValue4.TabIndex = 24;
            this.numericUpDownValue4.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.numericUpDownValue4.Value = new decimal(new int[] {
            60,
            0,
            0,
            0});
            this.numericUpDownValue4.ValueChanged += new System.EventHandler(this.numericUpDownValue_ValueChanged);
            // 
            // numericUpDownValue3
            // 
            this.numericUpDownValue3.Location = new System.Drawing.Point(38, 118);
            this.numericUpDownValue3.Name = "numericUpDownValue3";
            this.numericUpDownValue3.Size = new System.Drawing.Size(48, 21);
            this.numericUpDownValue3.TabIndex = 18;
            this.numericUpDownValue3.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.numericUpDownValue3.Value = new decimal(new int[] {
            20,
            0,
            0,
            0});
            this.numericUpDownValue3.ValueChanged += new System.EventHandler(this.numericUpDownValue_ValueChanged);
            // 
            // numericUpDownValue2
            // 
            this.numericUpDownValue2.Location = new System.Drawing.Point(38, 81);
            this.numericUpDownValue2.Name = "numericUpDownValue2";
            this.numericUpDownValue2.Size = new System.Drawing.Size(48, 21);
            this.numericUpDownValue2.TabIndex = 12;
            this.numericUpDownValue2.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.numericUpDownValue2.Value = new decimal(new int[] {
            15,
            0,
            0,
            0});
            this.numericUpDownValue2.ValueChanged += new System.EventHandler(this.numericUpDownValue_ValueChanged);
            // 
            // numericUpDownValue1
            // 
            this.numericUpDownValue1.Location = new System.Drawing.Point(38, 43);
            this.numericUpDownValue1.Name = "numericUpDownValue1";
            this.numericUpDownValue1.Size = new System.Drawing.Size(48, 21);
            this.numericUpDownValue1.TabIndex = 6;
            this.numericUpDownValue1.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.numericUpDownValue1.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.numericUpDownValue1.ValueChanged += new System.EventHandler(this.numericUpDownValue_ValueChanged);
            // 
            // numericUpDownDisplacement1
            // 
            this.numericUpDownDisplacement1.DecimalPlaces = 2;
            this.numericUpDownDisplacement1.Increment = new decimal(new int[] {
            5,
            0,
            0,
            131072});
            this.numericUpDownDisplacement1.Location = new System.Drawing.Point(96, 43);
            this.numericUpDownDisplacement1.Maximum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDownDisplacement1.Name = "numericUpDownDisplacement1";
            this.numericUpDownDisplacement1.Size = new System.Drawing.Size(58, 21);
            this.numericUpDownDisplacement1.TabIndex = 7;
            this.numericUpDownDisplacement1.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.numericUpDownDisplacement1.Value = new decimal(new int[] {
            2,
            0,
            0,
            65536});
            this.numericUpDownDisplacement1.ValueChanged += new System.EventHandler(this.numericUpDownDisplacement_ValueChanged);
            // 
            // numericUpDownDisplacement6
            // 
            this.numericUpDownDisplacement6.DecimalPlaces = 2;
            this.numericUpDownDisplacement6.Increment = new decimal(new int[] {
            5,
            0,
            0,
            131072});
            this.numericUpDownDisplacement6.Location = new System.Drawing.Point(96, 232);
            this.numericUpDownDisplacement6.Maximum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDownDisplacement6.Name = "numericUpDownDisplacement6";
            this.numericUpDownDisplacement6.Size = new System.Drawing.Size(58, 21);
            this.numericUpDownDisplacement6.TabIndex = 37;
            this.numericUpDownDisplacement6.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.numericUpDownDisplacement6.Value = new decimal(new int[] {
            5,
            0,
            0,
            131072});
            this.numericUpDownDisplacement6.ValueChanged += new System.EventHandler(this.numericUpDownDisplacement_ValueChanged);
            // 
            // numericUpDownDisplacement5
            // 
            this.numericUpDownDisplacement5.DecimalPlaces = 2;
            this.numericUpDownDisplacement5.Increment = new decimal(new int[] {
            5,
            0,
            0,
            131072});
            this.numericUpDownDisplacement5.Location = new System.Drawing.Point(96, 194);
            this.numericUpDownDisplacement5.Maximum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDownDisplacement5.Name = "numericUpDownDisplacement5";
            this.numericUpDownDisplacement5.Size = new System.Drawing.Size(58, 21);
            this.numericUpDownDisplacement5.TabIndex = 31;
            this.numericUpDownDisplacement5.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.numericUpDownDisplacement5.Value = new decimal(new int[] {
            5,
            0,
            0,
            131072});
            this.numericUpDownDisplacement5.ValueChanged += new System.EventHandler(this.numericUpDownDisplacement_ValueChanged);
            // 
            // numericUpDownDisplacement4
            // 
            this.numericUpDownDisplacement4.DecimalPlaces = 2;
            this.numericUpDownDisplacement4.Increment = new decimal(new int[] {
            5,
            0,
            0,
            131072});
            this.numericUpDownDisplacement4.Location = new System.Drawing.Point(96, 156);
            this.numericUpDownDisplacement4.Maximum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDownDisplacement4.Name = "numericUpDownDisplacement4";
            this.numericUpDownDisplacement4.Size = new System.Drawing.Size(58, 21);
            this.numericUpDownDisplacement4.TabIndex = 25;
            this.numericUpDownDisplacement4.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.numericUpDownDisplacement4.Value = new decimal(new int[] {
            5,
            0,
            0,
            131072});
            this.numericUpDownDisplacement4.ValueChanged += new System.EventHandler(this.numericUpDownDisplacement_ValueChanged);
            // 
            // numericUpDownDisplacement3
            // 
            this.numericUpDownDisplacement3.DecimalPlaces = 2;
            this.numericUpDownDisplacement3.Increment = new decimal(new int[] {
            5,
            0,
            0,
            131072});
            this.numericUpDownDisplacement3.Location = new System.Drawing.Point(96, 118);
            this.numericUpDownDisplacement3.Maximum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDownDisplacement3.Name = "numericUpDownDisplacement3";
            this.numericUpDownDisplacement3.Size = new System.Drawing.Size(58, 21);
            this.numericUpDownDisplacement3.TabIndex = 19;
            this.numericUpDownDisplacement3.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.numericUpDownDisplacement3.Value = new decimal(new int[] {
            5,
            0,
            0,
            131072});
            this.numericUpDownDisplacement3.ValueChanged += new System.EventHandler(this.numericUpDownDisplacement_ValueChanged);
            // 
            // numericUpDownDisplacement2
            // 
            this.numericUpDownDisplacement2.DecimalPlaces = 2;
            this.numericUpDownDisplacement2.Increment = new decimal(new int[] {
            5,
            0,
            0,
            131072});
            this.numericUpDownDisplacement2.Location = new System.Drawing.Point(96, 81);
            this.numericUpDownDisplacement2.Maximum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDownDisplacement2.Name = "numericUpDownDisplacement2";
            this.numericUpDownDisplacement2.Size = new System.Drawing.Size(58, 21);
            this.numericUpDownDisplacement2.TabIndex = 13;
            this.numericUpDownDisplacement2.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.numericUpDownDisplacement2.Value = new decimal(new int[] {
            5,
            0,
            0,
            131072});
            this.numericUpDownDisplacement2.ValueChanged += new System.EventHandler(this.numericUpDownDisplacement_ValueChanged);
            // 
            // numericUpDownPieHeight
            // 
            this.numericUpDownPieHeight.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.numericUpDownPieHeight.DecimalPlaces = 2;
            this.numericUpDownPieHeight.Increment = new decimal(new int[] {
            5,
            0,
            0,
            131072});
            this.numericUpDownPieHeight.Location = new System.Drawing.Point(490, 350);
            this.numericUpDownPieHeight.Maximum = new decimal(new int[] {
            5,
            0,
            0,
            65536});
            this.numericUpDownPieHeight.Name = "numericUpDownPieHeight";
            this.numericUpDownPieHeight.Size = new System.Drawing.Size(57, 21);
            this.numericUpDownPieHeight.TabIndex = 5;
            this.numericUpDownPieHeight.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.numericUpDownPieHeight.Value = new decimal(new int[] {
            25,
            0,
            0,
            131072});
            this.numericUpDownPieHeight.ValueChanged += new System.EventHandler(this.numericUpDownPieHeight_ValueChanged);
            // 
            // label2
            // 
            this.label2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label2.Location = new System.Drawing.Point(403, 352);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(87, 17);
            this.label2.TabIndex = 4;
            this.label2.Text = "Pie &height:";
            this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // comboBoxEdgeType
            // 
            this.comboBoxEdgeType.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.comboBoxEdgeType.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBoxEdgeType.Location = new System.Drawing.Point(490, 419);
            this.comboBoxEdgeType.Name = "comboBoxEdgeType";
            this.comboBoxEdgeType.Size = new System.Drawing.Size(211, 20);
            this.comboBoxEdgeType.TabIndex = 10;
            this.comboBoxEdgeType.SelectedIndexChanged += new System.EventHandler(this.comboBoxEdgeType_SelectedIndexChanged);
            // 
            // label3
            // 
            this.label3.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label3.Location = new System.Drawing.Point(403, 421);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(87, 17);
            this.label3.TabIndex = 9;
            this.label3.Text = "&Edge color:";
            // 
            // groupBox4
            // 
            this.groupBox4.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.groupBox4.Controls.Add(this.numericUpDownBottomMargin);
            this.groupBox4.Controls.Add(this.numericUpDownTopMargin);
            this.groupBox4.Controls.Add(this.numericUpDownRightMargin);
            this.groupBox4.Controls.Add(this.numericUpDownLeftMargin);
            this.groupBox4.Controls.Add(this.label7);
            this.groupBox4.Controls.Add(this.label6);
            this.groupBox4.Controls.Add(this.label5);
            this.groupBox4.Controls.Add(this.label4);
            this.groupBox4.Location = new System.Drawing.Point(403, 236);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(298, 77);
            this.groupBox4.TabIndex = 2;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "&Margins";
            // 
            // numericUpDownBottomMargin
            // 
            this.numericUpDownBottomMargin.Location = new System.Drawing.Point(226, 47);
            this.numericUpDownBottomMargin.Maximum = new decimal(new int[] {
            20,
            0,
            0,
            0});
            this.numericUpDownBottomMargin.Name = "numericUpDownBottomMargin";
            this.numericUpDownBottomMargin.Size = new System.Drawing.Size(57, 21);
            this.numericUpDownBottomMargin.TabIndex = 7;
            this.numericUpDownBottomMargin.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.numericUpDownBottomMargin.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.numericUpDownBottomMargin.ValueChanged += new System.EventHandler(this.numericUpDownBottomMargin_ValueChanged);
            // 
            // numericUpDownTopMargin
            // 
            this.numericUpDownTopMargin.Location = new System.Drawing.Point(226, 22);
            this.numericUpDownTopMargin.Maximum = new decimal(new int[] {
            20,
            0,
            0,
            0});
            this.numericUpDownTopMargin.Name = "numericUpDownTopMargin";
            this.numericUpDownTopMargin.Size = new System.Drawing.Size(57, 21);
            this.numericUpDownTopMargin.TabIndex = 5;
            this.numericUpDownTopMargin.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.numericUpDownTopMargin.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.numericUpDownTopMargin.ValueChanged += new System.EventHandler(this.numericUpDownTopMargin_ValueChanged);
            // 
            // numericUpDownRightMargin
            // 
            this.numericUpDownRightMargin.Location = new System.Drawing.Point(77, 47);
            this.numericUpDownRightMargin.Maximum = new decimal(new int[] {
            20,
            0,
            0,
            0});
            this.numericUpDownRightMargin.Name = "numericUpDownRightMargin";
            this.numericUpDownRightMargin.Size = new System.Drawing.Size(57, 21);
            this.numericUpDownRightMargin.TabIndex = 3;
            this.numericUpDownRightMargin.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.numericUpDownRightMargin.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.numericUpDownRightMargin.ValueChanged += new System.EventHandler(this.numericUpDownRightMargin_ValueChanged);
            // 
            // numericUpDownLeftMargin
            // 
            this.numericUpDownLeftMargin.Location = new System.Drawing.Point(77, 22);
            this.numericUpDownLeftMargin.Maximum = new decimal(new int[] {
            20,
            0,
            0,
            0});
            this.numericUpDownLeftMargin.Name = "numericUpDownLeftMargin";
            this.numericUpDownLeftMargin.Size = new System.Drawing.Size(57, 21);
            this.numericUpDownLeftMargin.TabIndex = 1;
            this.numericUpDownLeftMargin.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.numericUpDownLeftMargin.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.numericUpDownLeftMargin.ValueChanged += new System.EventHandler(this.numericUpDownLeftMargin_ValueChanged);
            // 
            // label7
            // 
            this.label7.Location = new System.Drawing.Point(158, 50);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(53, 17);
            this.label7.TabIndex = 6;
            this.label7.Text = "&Bottom:";
            // 
            // label6
            // 
            this.label6.Location = new System.Drawing.Point(158, 24);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(48, 17);
            this.label6.TabIndex = 4;
            this.label6.Text = "&Top:";
            // 
            // label5
            // 
            this.label5.Location = new System.Drawing.Point(14, 50);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(48, 17);
            this.label5.TabIndex = 2;
            this.label5.Text = "&Right:";
            // 
            // label4
            // 
            this.label4.Location = new System.Drawing.Point(14, 24);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(48, 17);
            this.label4.TabIndex = 0;
            this.label4.Text = "&Left:";
            // 
            // buttonColor6
            // 
            this.buttonColor6.BackColor = System.Drawing.Color.DeepSkyBlue;
            this.buttonColor6.Location = new System.Drawing.Point(163, 232);
            this.buttonColor6.Name = "buttonColor6";
            this.buttonColor6.Size = new System.Drawing.Size(24, 21);
            this.buttonColor6.TabIndex = 38;
            this.buttonColor6.UseVisualStyleBackColor = false;
            this.buttonColor6.Click += new System.EventHandler(this.buttonColor6_Click);
            // 
            // buttonColor5
            // 
            this.buttonColor5.BackColor = System.Drawing.Color.Firebrick;
            this.buttonColor5.Location = new System.Drawing.Point(163, 194);
            this.buttonColor5.Name = "buttonColor5";
            this.buttonColor5.Size = new System.Drawing.Size(24, 21);
            this.buttonColor5.TabIndex = 32;
            this.buttonColor5.UseVisualStyleBackColor = false;
            this.buttonColor5.Click += new System.EventHandler(this.buttonColor5_Click);
            // 
            // buttonColor4
            // 
            this.buttonColor4.BackColor = System.Drawing.Color.Yellow;
            this.buttonColor4.Location = new System.Drawing.Point(163, 156);
            this.buttonColor4.Name = "buttonColor4";
            this.buttonColor4.Size = new System.Drawing.Size(24, 22);
            this.buttonColor4.TabIndex = 26;
            this.buttonColor4.UseVisualStyleBackColor = false;
            this.buttonColor4.Click += new System.EventHandler(this.buttonColor4_Click);
            // 
            // buttonColor3
            // 
            this.buttonColor3.BackColor = System.Drawing.Color.Blue;
            this.buttonColor3.Location = new System.Drawing.Point(163, 118);
            this.buttonColor3.Name = "buttonColor3";
            this.buttonColor3.Size = new System.Drawing.Size(24, 22);
            this.buttonColor3.TabIndex = 20;
            this.buttonColor3.UseVisualStyleBackColor = false;
            this.buttonColor3.Click += new System.EventHandler(this.buttonColor3_Click);
            // 
            // buttonColor2
            // 
            this.buttonColor2.BackColor = System.Drawing.Color.LimeGreen;
            this.buttonColor2.Location = new System.Drawing.Point(163, 81);
            this.buttonColor2.Name = "buttonColor2";
            this.buttonColor2.Size = new System.Drawing.Size(24, 21);
            this.buttonColor2.TabIndex = 14;
            this.buttonColor2.UseVisualStyleBackColor = false;
            this.buttonColor2.Click += new System.EventHandler(this.buttonColor2_Click);
            // 
            // buttonColor1
            // 
            this.buttonColor1.BackColor = System.Drawing.Color.Red;
            this.buttonColor1.Location = new System.Drawing.Point(163, 43);
            this.buttonColor1.Name = "buttonColor1";
            this.buttonColor1.Size = new System.Drawing.Size(24, 22);
            this.buttonColor1.TabIndex = 8;
            this.buttonColor1.UseVisualStyleBackColor = false;
            this.buttonColor1.Click += new System.EventHandler(this.buttonColor1_Click);
            // 
            // groupBox6
            // 
            this.groupBox6.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.groupBox6.Controls.Add(this.textBoxText6);
            this.groupBox6.Controls.Add(this.textBoxText5);
            this.groupBox6.Controls.Add(this.textBoxText4);
            this.groupBox6.Controls.Add(this.textBoxText3);
            this.groupBox6.Controls.Add(this.textBoxText2);
            this.groupBox6.Controls.Add(this.textBoxText1);
            this.groupBox6.Controls.Add(this.label14);
            this.groupBox6.Controls.Add(this.textBoxToolTip6);
            this.groupBox6.Controls.Add(this.textBoxToolTip5);
            this.groupBox6.Controls.Add(this.textBoxToolTip4);
            this.groupBox6.Controls.Add(this.textBoxToolTip3);
            this.groupBox6.Controls.Add(this.textBoxToolTip2);
            this.groupBox6.Controls.Add(this.textBoxToolTip1);
            this.groupBox6.Controls.Add(this.label12);
            this.groupBox6.Controls.Add(this.checkBox6);
            this.groupBox6.Controls.Add(this.checkBox5);
            this.groupBox6.Controls.Add(this.checkBox4);
            this.groupBox6.Controls.Add(this.checkBox3);
            this.groupBox6.Controls.Add(this.checkBox2);
            this.groupBox6.Controls.Add(this.checkBox1);
            this.groupBox6.Controls.Add(this.label10);
            this.groupBox6.Controls.Add(this.label9);
            this.groupBox6.Controls.Add(this.label8);
            this.groupBox6.Controls.Add(this.numericUpDownValue2);
            this.groupBox6.Controls.Add(this.numericUpDownValue3);
            this.groupBox6.Controls.Add(this.numericUpDownValue6);
            this.groupBox6.Controls.Add(this.numericUpDownValue1);
            this.groupBox6.Controls.Add(this.numericUpDownValue5);
            this.groupBox6.Controls.Add(this.numericUpDownValue4);
            this.groupBox6.Controls.Add(this.numericUpDownDisplacement1);
            this.groupBox6.Controls.Add(this.numericUpDownDisplacement6);
            this.groupBox6.Controls.Add(this.numericUpDownDisplacement3);
            this.groupBox6.Controls.Add(this.numericUpDownDisplacement4);
            this.groupBox6.Controls.Add(this.numericUpDownDisplacement5);
            this.groupBox6.Controls.Add(this.numericUpDownDisplacement2);
            this.groupBox6.Controls.Add(this.buttonColor3);
            this.groupBox6.Controls.Add(this.buttonColor6);
            this.groupBox6.Controls.Add(this.buttonColor5);
            this.groupBox6.Controls.Add(this.buttonColor2);
            this.groupBox6.Controls.Add(this.buttonColor4);
            this.groupBox6.Controls.Add(this.buttonColor1);
            this.groupBox6.Location = new System.Drawing.Point(10, 236);
            this.groupBox6.Name = "groupBox6";
            this.groupBox6.Size = new System.Drawing.Size(384, 267);
            this.groupBox6.TabIndex = 1;
            this.groupBox6.TabStop = false;
            this.groupBox6.Text = "&Pie slices";
            // 
            // textBoxText6
            // 
            this.textBoxText6.Location = new System.Drawing.Point(202, 232);
            this.textBoxText6.Name = "textBoxText6";
            this.textBoxText6.Size = new System.Drawing.Size(86, 21);
            this.textBoxText6.TabIndex = 39;
            this.textBoxText6.Text = "cyan";
            this.textBoxText6.TextChanged += new System.EventHandler(this.textBoxText_TextChanged);
            // 
            // textBoxText5
            // 
            this.textBoxText5.Location = new System.Drawing.Point(202, 194);
            this.textBoxText5.Name = "textBoxText5";
            this.textBoxText5.Size = new System.Drawing.Size(86, 21);
            this.textBoxText5.TabIndex = 33;
            this.textBoxText5.Text = "brown";
            this.textBoxText5.TextChanged += new System.EventHandler(this.textBoxText_TextChanged);
            // 
            // textBoxText4
            // 
            this.textBoxText4.Location = new System.Drawing.Point(202, 156);
            this.textBoxText4.Name = "textBoxText4";
            this.textBoxText4.Size = new System.Drawing.Size(86, 21);
            this.textBoxText4.TabIndex = 27;
            this.textBoxText4.Text = "yellow";
            this.textBoxText4.TextChanged += new System.EventHandler(this.textBoxText_TextChanged);
            // 
            // textBoxText3
            // 
            this.textBoxText3.Location = new System.Drawing.Point(202, 118);
            this.textBoxText3.Name = "textBoxText3";
            this.textBoxText3.Size = new System.Drawing.Size(86, 21);
            this.textBoxText3.TabIndex = 21;
            this.textBoxText3.Text = "blue";
            this.textBoxText3.TextChanged += new System.EventHandler(this.textBoxText_TextChanged);
            // 
            // textBoxText2
            // 
            this.textBoxText2.Location = new System.Drawing.Point(202, 81);
            this.textBoxText2.Name = "textBoxText2";
            this.textBoxText2.Size = new System.Drawing.Size(86, 21);
            this.textBoxText2.TabIndex = 15;
            this.textBoxText2.Text = "green";
            this.textBoxText2.TextChanged += new System.EventHandler(this.textBoxText_TextChanged);
            // 
            // textBoxText1
            // 
            this.textBoxText1.Location = new System.Drawing.Point(202, 43);
            this.textBoxText1.Name = "textBoxText1";
            this.textBoxText1.Size = new System.Drawing.Size(86, 21);
            this.textBoxText1.TabIndex = 9;
            this.textBoxText1.Text = "red";
            this.textBoxText1.TextChanged += new System.EventHandler(this.textBoxText_TextChanged);
            // 
            // label14
            // 
            this.label14.Location = new System.Drawing.Point(202, 22);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(76, 17);
            this.label14.TabIndex = 3;
            this.label14.Text = "Text";
            this.label14.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // textBoxToolTip6
            // 
            this.textBoxToolTip6.Location = new System.Drawing.Point(298, 232);
            this.textBoxToolTip6.Name = "textBoxToolTip6";
            this.textBoxToolTip6.Size = new System.Drawing.Size(76, 21);
            this.textBoxToolTip6.TabIndex = 40;
            this.textBoxToolTip6.TextChanged += new System.EventHandler(this.textBoxToolTip_TextChanged);
            // 
            // textBoxToolTip5
            // 
            this.textBoxToolTip5.Location = new System.Drawing.Point(298, 194);
            this.textBoxToolTip5.Name = "textBoxToolTip5";
            this.textBoxToolTip5.Size = new System.Drawing.Size(76, 21);
            this.textBoxToolTip5.TabIndex = 34;
            this.textBoxToolTip5.TextChanged += new System.EventHandler(this.textBoxToolTip_TextChanged);
            // 
            // textBoxToolTip4
            // 
            this.textBoxToolTip4.Location = new System.Drawing.Point(298, 156);
            this.textBoxToolTip4.Name = "textBoxToolTip4";
            this.textBoxToolTip4.Size = new System.Drawing.Size(76, 21);
            this.textBoxToolTip4.TabIndex = 28;
            this.textBoxToolTip4.TextChanged += new System.EventHandler(this.textBoxToolTip_TextChanged);
            // 
            // textBoxToolTip3
            // 
            this.textBoxToolTip3.Location = new System.Drawing.Point(298, 118);
            this.textBoxToolTip3.Name = "textBoxToolTip3";
            this.textBoxToolTip3.Size = new System.Drawing.Size(76, 21);
            this.textBoxToolTip3.TabIndex = 22;
            this.textBoxToolTip3.TextChanged += new System.EventHandler(this.textBoxToolTip_TextChanged);
            // 
            // textBoxToolTip2
            // 
            this.textBoxToolTip2.Location = new System.Drawing.Point(298, 81);
            this.textBoxToolTip2.Name = "textBoxToolTip2";
            this.textBoxToolTip2.Size = new System.Drawing.Size(76, 21);
            this.textBoxToolTip2.TabIndex = 16;
            this.textBoxToolTip2.TextChanged += new System.EventHandler(this.textBoxToolTip_TextChanged);
            // 
            // textBoxToolTip1
            // 
            this.textBoxToolTip1.Location = new System.Drawing.Point(298, 43);
            this.textBoxToolTip1.Name = "textBoxToolTip1";
            this.textBoxToolTip1.Size = new System.Drawing.Size(76, 21);
            this.textBoxToolTip1.TabIndex = 10;
            this.textBoxToolTip1.TextChanged += new System.EventHandler(this.textBoxToolTip_TextChanged);
            // 
            // label12
            // 
            this.label12.Location = new System.Drawing.Point(298, 22);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(76, 17);
            this.label12.TabIndex = 4;
            this.label12.Text = "ToolTip";
            this.label12.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // checkBox6
            // 
            this.checkBox6.Checked = true;
            this.checkBox6.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBox6.Location = new System.Drawing.Point(10, 229);
            this.checkBox6.Name = "checkBox6";
            this.checkBox6.Size = new System.Drawing.Size(19, 26);
            this.checkBox6.TabIndex = 35;
            this.checkBox6.CheckedChanged += new System.EventHandler(this.checkBox6_CheckedChanged);
            // 
            // checkBox5
            // 
            this.checkBox5.Checked = true;
            this.checkBox5.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBox5.Location = new System.Drawing.Point(10, 192);
            this.checkBox5.Name = "checkBox5";
            this.checkBox5.Size = new System.Drawing.Size(19, 26);
            this.checkBox5.TabIndex = 29;
            this.checkBox5.CheckedChanged += new System.EventHandler(this.checkBox5_CheckedChanged);
            // 
            // checkBox4
            // 
            this.checkBox4.Checked = true;
            this.checkBox4.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBox4.Location = new System.Drawing.Point(10, 154);
            this.checkBox4.Name = "checkBox4";
            this.checkBox4.Size = new System.Drawing.Size(19, 26);
            this.checkBox4.TabIndex = 23;
            this.checkBox4.CheckedChanged += new System.EventHandler(this.checkBox4_CheckedChanged);
            // 
            // checkBox3
            // 
            this.checkBox3.Checked = true;
            this.checkBox3.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBox3.Location = new System.Drawing.Point(10, 116);
            this.checkBox3.Name = "checkBox3";
            this.checkBox3.Size = new System.Drawing.Size(19, 26);
            this.checkBox3.TabIndex = 17;
            this.checkBox3.CheckedChanged += new System.EventHandler(this.checkBox3_CheckedChanged);
            // 
            // checkBox2
            // 
            this.checkBox2.Checked = true;
            this.checkBox2.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBox2.Location = new System.Drawing.Point(10, 79);
            this.checkBox2.Name = "checkBox2";
            this.checkBox2.Size = new System.Drawing.Size(19, 25);
            this.checkBox2.TabIndex = 11;
            this.checkBox2.CheckedChanged += new System.EventHandler(this.checkBox2_CheckedChanged);
            // 
            // checkBox1
            // 
            this.checkBox1.Checked = true;
            this.checkBox1.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBox1.Location = new System.Drawing.Point(10, 41);
            this.checkBox1.Name = "checkBox1";
            this.checkBox1.Size = new System.Drawing.Size(19, 26);
            this.checkBox1.TabIndex = 5;
            this.checkBox1.CheckedChanged += new System.EventHandler(this.checkBox1_CheckedChanged);
            // 
            // label10
            // 
            this.label10.Location = new System.Drawing.Point(154, 22);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(45, 17);
            this.label10.TabIndex = 2;
            this.label10.Text = "Color";
            this.label10.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label9
            // 
            this.label9.Location = new System.Drawing.Point(96, 22);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(58, 17);
            this.label9.TabIndex = 1;
            this.label9.Text = "Offset";
            this.label9.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // label8
            // 
            this.label8.Location = new System.Drawing.Point(38, 22);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(58, 17);
            this.label8.TabIndex = 0;
            this.label8.Text = "Value";
            this.label8.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // label11
            // 
            this.label11.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label11.Location = new System.Drawing.Point(403, 451);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(87, 17);
            this.label11.TabIndex = 11;
            this.label11.Text = "Edge &width:";
            // 
            // numericUpDownEdgeLineWidth
            // 
            this.numericUpDownEdgeLineWidth.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.numericUpDownEdgeLineWidth.DecimalPlaces = 1;
            this.numericUpDownEdgeLineWidth.Location = new System.Drawing.Point(490, 449);
            this.numericUpDownEdgeLineWidth.Maximum = new decimal(new int[] {
            5,
            0,
            0,
            0});
            this.numericUpDownEdgeLineWidth.Name = "numericUpDownEdgeLineWidth";
            this.numericUpDownEdgeLineWidth.Size = new System.Drawing.Size(57, 21);
            this.numericUpDownEdgeLineWidth.TabIndex = 12;
            this.numericUpDownEdgeLineWidth.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.numericUpDownEdgeLineWidth.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDownEdgeLineWidth.ValueChanged += new System.EventHandler(this.numericUpDownEdgeLineWidth_ValueChanged);
            // 
            // checkBoxFitChart
            // 
            this.checkBoxFitChart.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.checkBoxFitChart.Location = new System.Drawing.Point(403, 322);
            this.checkBoxFitChart.Name = "checkBoxFitChart";
            this.checkBoxFitChart.Size = new System.Drawing.Size(163, 17);
            this.checkBoxFitChart.TabIndex = 3;
            this.checkBoxFitChart.Text = "&Fit chart to panel";
            this.checkBoxFitChart.CheckedChanged += new System.EventHandler(this.checkBoxFitChart_CheckedChanged);
            // 
            // label13
            // 
            this.label13.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label13.Location = new System.Drawing.Point(403, 481);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(58, 17);
            this.label13.TabIndex = 13;
            this.label13.Text = "&Alpha:";
            // 
            // m_numericUpDownAlpha
            // 
            this.m_numericUpDownAlpha.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.m_numericUpDownAlpha.Location = new System.Drawing.Point(490, 479);
            this.m_numericUpDownAlpha.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.m_numericUpDownAlpha.Name = "m_numericUpDownAlpha";
            this.m_numericUpDownAlpha.Size = new System.Drawing.Size(57, 21);
            this.m_numericUpDownAlpha.TabIndex = 14;
            this.m_numericUpDownAlpha.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.m_numericUpDownAlpha.Value = new decimal(new int[] {
            122,
            0,
            0,
            0});
            this.m_numericUpDownAlpha.ValueChanged += new System.EventHandler(this.m_numericUpDownAlpha_ValueChanged);
            // 
            // m_buttonPrint
            // 
            this.m_buttonPrint.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.m_buttonPrint.Location = new System.Drawing.Point(605, 477);
            this.m_buttonPrint.Name = "m_buttonPrint";
            this.m_buttonPrint.Size = new System.Drawing.Size(90, 25);
            this.m_buttonPrint.TabIndex = 15;
            this.m_buttonPrint.Text = "&Print";
            this.m_buttonPrint.Click += new System.EventHandler(this.m_buttonPrint_Click);
            // 
            // m_panelDrawing
            // 
            this.m_panelDrawing.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.m_panelDrawing.BackColor = System.Drawing.SystemColors.Window;
            this.m_panelDrawing.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.m_panelDrawing.Location = new System.Drawing.Point(10, 9);
            this.m_panelDrawing.Name = "m_panelDrawing";
            this.m_panelDrawing.Size = new System.Drawing.Size(693, 218);
            this.m_panelDrawing.TabIndex = 16;
            this.m_panelDrawing.ToolTips = null;
            // 
            // Form1
            // 
            this.AutoScaleBaseSize = new System.Drawing.Size(6, 14);
            this.ClientSize = new System.Drawing.Size(712, 517);
            this.Controls.Add(this.m_buttonPrint);
            this.Controls.Add(this.m_numericUpDownAlpha);
            this.Controls.Add(this.label13);
            this.Controls.Add(this.checkBoxFitChart);
            this.Controls.Add(this.numericUpDownEdgeLineWidth);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.groupBox6);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.comboBoxEdgeType);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.numericUpDownPieHeight);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.numericUpDownAngle);
            this.Controls.Add(this.m_panelDrawing);
            this.MinimumSize = new System.Drawing.Size(720, 409);
            this.Name = "Form1";
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Show;
            this.Text = "Pie Chart";
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownAngle)).EndInit();
            this.groupBox1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownValue6)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownValue5)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownValue4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownValue3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownValue2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownValue1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownDisplacement1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownDisplacement6)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownDisplacement5)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownDisplacement4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownDisplacement3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownDisplacement2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownPieHeight)).EndInit();
            this.groupBox4.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownBottomMargin)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownTopMargin)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownRightMargin)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownLeftMargin)).EndInit();
            this.groupBox6.ResumeLayout(false);
            this.groupBox6.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownEdgeLineWidth)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.m_numericUpDownAlpha)).EndInit();
            this.ResumeLayout(false);

        }
		#endregion

        #region Get properties

        private Color[] Colors {
            get {
                ArrayList colors = new ArrayList();
                if (buttonColor1.Enabled)
                    colors.Add(Color.FromArgb((int)m_numericUpDownAlpha.Value, buttonColor1.BackColor));
                if (buttonColor2.Enabled)
                    colors.Add(Color.FromArgb((int)m_numericUpDownAlpha.Value, buttonColor2.BackColor));
                if (buttonColor3.Enabled)
                    colors.Add(Color.FromArgb((int)m_numericUpDownAlpha.Value, buttonColor3.BackColor));
                if (buttonColor4.Enabled)
                    colors.Add(Color.FromArgb((int)m_numericUpDownAlpha.Value, buttonColor4.BackColor));
                if (buttonColor5.Enabled)
                    colors.Add(Color.FromArgb((int)m_numericUpDownAlpha.Value, buttonColor5.BackColor));
                if (buttonColor6.Enabled)
                    colors.Add(Color.FromArgb((int)m_numericUpDownAlpha.Value, buttonColor6.BackColor));
                return (Color[])colors.ToArray(typeof(Color));
            }
        }

        private decimal[] Values {
            get {
                ArrayList values = new ArrayList();
                if (numericUpDownValue1.Enabled)
                    values.Add(numericUpDownValue1.Value);
                if (numericUpDownValue2.Enabled)
                    values.Add(numericUpDownValue2.Value);
                if (numericUpDownValue3.Enabled)
                    values.Add(numericUpDownValue3.Value);
                if (numericUpDownValue4.Enabled)
                    values.Add(numericUpDownValue4.Value);
                if (numericUpDownValue5.Enabled)
                    values.Add(numericUpDownValue5.Value);
                if (numericUpDownValue6.Enabled)
                    values.Add(numericUpDownValue6.Value);
                return (decimal[])values.ToArray(typeof(decimal));
            }
        }

        private float[] Displacements {
            get {
                ArrayList displacements = new ArrayList();
                if (numericUpDownDisplacement1.Enabled)
                    displacements.Add((float)numericUpDownDisplacement1.Value);
                if (numericUpDownDisplacement2.Enabled)
                    displacements.Add((float)numericUpDownDisplacement2.Value);
                if (numericUpDownDisplacement3.Enabled)
                    displacements.Add((float)numericUpDownDisplacement3.Value);
                if (numericUpDownDisplacement4.Enabled)
                    displacements.Add((float)numericUpDownDisplacement4.Value);
                if (numericUpDownDisplacement5.Enabled)
                    displacements.Add((float)numericUpDownDisplacement5.Value);
                if (numericUpDownDisplacement6.Enabled)
                    displacements.Add((float)numericUpDownDisplacement6.Value);
                return (float[])displacements.ToArray(typeof(float));
            }
        }

        private string[] Texts {
            get {
                ArrayList texts = new ArrayList();
                if (textBoxText1.Enabled)
                    texts.Add(textBoxText1.Text);
                if (textBoxText2.Enabled)
                    texts.Add(textBoxText2.Text);
                if (textBoxText3.Enabled)
                    texts.Add(textBoxText3.Text);
                if (textBoxText4.Enabled)
                    texts.Add(textBoxText4.Text);
                if (textBoxText5.Enabled)
                    texts.Add(textBoxText5.Text);
                if (textBoxText6.Enabled)
                    texts.Add(textBoxText6.Text);
                return (string[])texts.ToArray(typeof(string));
            }
        }

        private string[] ToolTips {
            get { 
                ArrayList toolTips = new ArrayList();
                if (textBoxToolTip1.Enabled)
                    toolTips.Add(textBoxToolTip1.Text);
                if (textBoxToolTip2.Enabled)
                    toolTips.Add(textBoxToolTip2.Text);
                if (textBoxToolTip3.Enabled)
                    toolTips.Add(textBoxToolTip3.Text);
                if (textBoxToolTip4.Enabled)
                    toolTips.Add(textBoxToolTip4.Text);
                if (textBoxToolTip5.Enabled)
                    toolTips.Add(textBoxToolTip5.Text);
                if (textBoxToolTip6.Enabled)
                    toolTips.Add(textBoxToolTip6.Text);
                return (string[])toolTips.ToArray(typeof(string));
            }
        }

        #endregion // Get properties

        private void InitializeChart() {
            SetValues();
            SetPieDisplacements();
            SetColors();
            SetTexts();
            SetToolTips();
            m_panelDrawing.LeftMargin        = (float)numericUpDownLeftMargin.Value;
            m_panelDrawing.RightMargin       = (float)numericUpDownRightMargin.Value;
            m_panelDrawing.TopMargin         = (float)numericUpDownTopMargin.Value;
            m_panelDrawing.BottomMargin      = (float)numericUpDownBottomMargin.Value;
            m_panelDrawing.FitChart          = checkBoxFitChart.Checked;
            m_panelDrawing.SliceRelativeHeight = (float)numericUpDownPieHeight.Value;
            m_panelDrawing.InitialAngle      = (float)numericUpDownAngle.Value;
            m_panelDrawing.EdgeLineWidth     = (float)numericUpDownEdgeLineWidth.Value;
        }

        private void FillEdgeColorTypeListBox() {
            string[] types = Enum.GetNames(typeof(EdgeColorType));
            comboBoxEdgeType.Items.AddRange(types);
            comboBoxEdgeType.SelectedIndex = (int)EdgeColorType.DarkerThanSurface;
        }

        private void UpdateChart() {
            SetValues();
            SetPieDisplacements();
            SetColors();
            SetTexts();
            SetToolTips();
        }

        private void SetValues() {
            m_panelDrawing.Values = Values;
        }

        private void SetPieDisplacements() {
            m_panelDrawing.SliceRelativeDisplacements = Displacements;
        }

        private void SetColors() {
            m_panelDrawing.Colors = Colors;
        }

        private void SetTexts() {
            m_panelDrawing.Texts = Texts;
        }

        private void SetToolTips() {
            m_panelDrawing.ToolTips = ToolTips;
        }

        #region Control event handlers

        private void checkBox1_CheckedChanged(object sender, System.EventArgs e) {
            numericUpDownValue1.Enabled = checkBox1.Checked;
            numericUpDownDisplacement1.Enabled = checkBox1.Checked;
            buttonColor1.Enabled = checkBox1.Checked;
            textBoxText1.Enabled = checkBox1.Checked;
            textBoxToolTip1.Enabled = checkBox1.Checked;
            UpdateChart();
        }

        private void checkBox2_CheckedChanged(object sender, System.EventArgs e) {
            numericUpDownValue2.Enabled = checkBox2.Checked;
            numericUpDownDisplacement2.Enabled = checkBox2.Checked;
            buttonColor2.Enabled = checkBox2.Checked;
            textBoxText2.Enabled = checkBox2.Checked;
            textBoxToolTip2.Enabled = checkBox2.Checked;
            UpdateChart();
        }

        private void checkBox3_CheckedChanged(object sender, System.EventArgs e) {
            numericUpDownValue3.Enabled = checkBox3.Checked;
            numericUpDownDisplacement3.Enabled = checkBox3.Checked;
            buttonColor3.Enabled = checkBox3.Checked;
            textBoxText3.Enabled = checkBox3.Checked;
            textBoxToolTip3.Enabled = checkBox3.Checked;
            UpdateChart();
        }

        private void checkBox4_CheckedChanged(object sender, System.EventArgs e) {
            numericUpDownValue4.Enabled = checkBox4.Checked;
            numericUpDownDisplacement4.Enabled = checkBox4.Checked;
            buttonColor4.Enabled = checkBox4.Checked;
            textBoxText4.Enabled = checkBox4.Checked;
            textBoxToolTip4.Enabled = checkBox4.Checked;
            UpdateChart();
        }

        private void checkBox5_CheckedChanged(object sender, System.EventArgs e) {
            numericUpDownValue5.Enabled = checkBox5.Checked;
            numericUpDownDisplacement5.Enabled = checkBox5.Checked;
            buttonColor5.Enabled = checkBox5.Checked;
            textBoxText5.Enabled = checkBox5.Checked;
            textBoxToolTip5.Enabled = checkBox5.Checked;
            UpdateChart();
        }

        private void checkBox6_CheckedChanged(object sender, System.EventArgs e) {
            numericUpDownValue6.Enabled = checkBox6.Checked;
            numericUpDownDisplacement6.Enabled = checkBox6.Checked;
            buttonColor6.Enabled = checkBox6.Checked;
            textBoxText6.Enabled = checkBox6.Checked;
            textBoxToolTip6.Enabled = checkBox6.Checked;
            UpdateChart();
        }

        private void numericUpDownValue_ValueChanged(object sender, System.EventArgs e) {
            SetValues();
        }

        private void numericUpDownDisplacement_ValueChanged(object sender, System.EventArgs e) {
            SetPieDisplacements();
        }

        private void buttonColor1_Click(object sender, System.EventArgs e) {
            if (m_colorDialog.ShowDialog() == DialogResult.OK) {
                buttonColor1.BackColor = m_colorDialog.Color;
                SetColors();
            }
        }

        private void buttonColor2_Click(object sender, System.EventArgs e) {
            if (m_colorDialog.ShowDialog() == DialogResult.OK) {
                buttonColor2.BackColor = m_colorDialog.Color;
                SetColors();
            }
        }

        private void buttonColor3_Click(object sender, System.EventArgs e) {
            if (m_colorDialog.ShowDialog() == DialogResult.OK) {
                buttonColor3.BackColor = m_colorDialog.Color;
                SetColors();
            }
        }

        private void buttonColor4_Click(object sender, System.EventArgs e) {
            if (m_colorDialog.ShowDialog() == DialogResult.OK) {
                buttonColor4.BackColor = m_colorDialog.Color;
                SetColors();
            }
        }

        private void buttonColor5_Click(object sender, System.EventArgs e) {
            if (m_colorDialog.ShowDialog() == DialogResult.OK) {
                buttonColor5.BackColor = m_colorDialog.Color;
                SetColors();
            }
        }

        private void buttonColor6_Click(object sender, System.EventArgs e) {
            if (m_colorDialog.ShowDialog() == DialogResult.OK) {
                buttonColor6.BackColor = m_colorDialog.Color;
                SetColors();
            }
        }

        private void textBoxText_TextChanged(object sender, System.EventArgs e) {
            SetTexts();
        }

        private void textBoxToolTip_TextChanged(object sender, System.EventArgs e) {
            SetToolTips();
        }

        private void numericUpDownLeftMargin_ValueChanged(object sender, System.EventArgs e) {
            m_panelDrawing.LeftMargin = (float)numericUpDownLeftMargin.Value;
        }

        private void numericUpDownRightMargin_ValueChanged(object sender, System.EventArgs e) {
            m_panelDrawing.RightMargin = (float)numericUpDownRightMargin.Value;
        }

        private void numericUpDownTopMargin_ValueChanged(object sender, System.EventArgs e) {
            m_panelDrawing.TopMargin = (float)numericUpDownTopMargin.Value;
        }

        private void numericUpDownBottomMargin_ValueChanged(object sender, System.EventArgs e) {
            m_panelDrawing.BottomMargin = (float)numericUpDownBottomMargin.Value;
        }

        private void numericUpDownPieHeight_ValueChanged(object sender, System.EventArgs e) {
            m_panelDrawing.SliceRelativeHeight = (float)numericUpDownPieHeight.Value;
        }

        private void radioButtonShadowStyle_Changed(object sender, System.EventArgs e) {
            if (radioButtonShadowStyleNone.Checked)
                m_panelDrawing.ShadowStyle = ShadowStyle.NoShadow;
            else if (radioButtonShadowStyleUniform.Checked)
                m_panelDrawing.ShadowStyle = ShadowStyle.UniformShadow;
            else
                m_panelDrawing.ShadowStyle = ShadowStyle.GradualShadow;
        }

        private void numericUpDownAngle_ValueChanged(object sender, System.EventArgs e) {
            m_panelDrawing.InitialAngle = (float)numericUpDownAngle.Value;
        }

        private void comboBoxEdgeType_SelectedIndexChanged(object sender, System.EventArgs e) {
            m_panelDrawing.EdgeColorType = (EdgeColorType)comboBoxEdgeType.SelectedIndex;
        }

        private void numericUpDownEdgeLineWidth_ValueChanged(object sender, System.EventArgs e) {
            m_panelDrawing.EdgeLineWidth = (float)numericUpDownEdgeLineWidth.Value;
        }

        private void checkBoxFitChart_CheckedChanged(object sender, System.EventArgs e) {
            m_panelDrawing.FitChart = checkBoxFitChart.Checked;
        }
 
        private void m_numericUpDownAlpha_ValueChanged(object sender, System.EventArgs e) {
            SetColors();
        }

        private void m_buttonPrint_Click(object sender, System.EventArgs e) {
            m_printDialog = new PrintDialog();
            PrintDocument pd = new PrintDocument();
            m_printDialog.Document = pd;
            if (m_printDialog.ShowDialog(this) == DialogResult.OK)
            {
                pd.PrinterSettings = m_printDialog.PrinterSettings;
                PieChart3D pieChart = new PieChart3D(100, 100, 400, 300, Values, (float)numericUpDownPieHeight.Value);
                pieChart.Colors = Colors;
                pieChart.SliceRelativeDisplacements = Displacements;
                pieChart.InitialAngle = (float)numericUpDownAngle.Value;
                pieChart.Texts = Texts;
                pieChart.Font = new Font("Arial", 10F);
                pieChart.ForeColor = SystemColors.WindowText;
                PrintChart pc = new PrintChart(pieChart);
                pc.DoPrint(pd);
            }
        }

        #endregion Control event handlers

        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main() {
            try {
                Application.Run(new Form1());
            }
            catch (Exception e) {
                MessageBox.Show(e.ToString());
            }
        }
    }
}