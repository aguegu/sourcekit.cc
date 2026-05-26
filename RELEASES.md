# Releases

Internal change log for the sourcekit.cc docs site. Not published to the website (lives outside `docs/`).

## 0.1.1 — unreleased

- Dev server now binds to `0.0.0.0` (configured via `vite.server.host` in `.vitepress/config.js`) so the server is reachable from other hosts on the LAN.
- Mini Tank Starter Kit, Session 1 Step 1: pedagogical rework as a teacher's guide for ~10yo students with ~2 years of English. Restructured into four narrative arcs — *Meet the Parts → Make the Motor Spin → What About Speed? → Variable Speed With One Battery* — with three hands-on experiments in `::: info` containers (Simple Circuit, Bigger Battery, Speed Control by Timing) progressively landing **circuit**, **switch**, **polarity reversal**, **voltage** (named after Volta), **series stacking**, and **PWM**. Closes by naming PWM, then uses the "person too big to ride the tank" framing to motivate MeshMass. *Battery Is Everywhere* now opens with a vocabulary-check question. Safety Rules wrapped in `::: danger`. Dropped `1.x.x` numbering throughout Step 1.
- Mini Tank Starter Kit, Session 1 Step 1: tightened the closing. The three fragmented blocks (*Think About It! / The Problem / This is why we need MeshMass!*) are merged into a single *The Speed Problem* section that bridges directly into Step 2.
- Mini Tank Starter Kit, Session 1 Step 1: replaced the *How to Control It?* bullet list with an *Experiment: A Simple Circuit* section. The experiment introduces the **circuit** concept (1S battery + N20 motor + two wires), folds in a short-circuit safety caution, the **switch** concept (on/off via interrupting one wire), and the polarity reversal that was previously listed.

## 0.1.0 — 2026-05-26

- Dev server now binds to `0.0.0.0` so it's reachable from other hosts on the LAN.
- Removed unused `medium-zoom` Layout customization; image lightbox is handled by `vitepress-plugin-lightbox`.
- Removed dead `themeConfig.localeLinks` block from `.vitepress/config.js` (locale switcher is generated automatically from the `locales` config).
- Cleaned up commented scaffolding in `.vitepress/theme/index.js`.
- Fixed `MeshMass-Mini-Tank-Starter-Kit.md`: removed duplicate `## Programming` heading and moved tools/accessories out of the "3D Printed Parts" section.
- Updated `CLAUDE.md` to match repo reality (VitePress version, plugins in use, theme structure, product list).
- Deleted stale `MESHMASS-RX4M4S-MARKET-INSIGHTS.md` planning doc from the repo root.
