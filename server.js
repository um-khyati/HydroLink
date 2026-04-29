const express = require("express");
const { exec } = require("child_process");
const path = require("path");
const app = express();

app.use(express.json());
app.use(express.static("public")); // This serves your HTML

app.get("/api/route", (req, res) => {
  const { algo, src, dst, disabled } = req.query;

  // Path to your specific executable
  const executable = path.join(__dirname, "hydrolink_api");

  // Command: executable algo disabled_csv src_id dst_id
  const cmd = `"${executable}" ${algo} "${disabled || ""}" ${src} ${dst}`;

  exec(cmd, (error, stdout, stderr) => {
    if (error) {
      console.error(`Exec error: ${error}`);
      return res.status(500).json({ error: "Internal Server Error" });
    }
    try {
      res.json(JSON.parse(stdout));
    } catch (e) {
      res.status(500).json({ error: "Invalid JSON from C++", details: stdout });
    }
  });
});

const PORT = 3000;
app.listen(PORT, () =>
  console.log(`HydroNet Server running on http://localhost:${PORT}`),
);
